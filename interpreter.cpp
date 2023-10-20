#include "interpreter.hpp"

// system includes
#include <stack>
#include <stdexcept>
#include <iostream>

// module includes
#include "tokenize.hpp"
#include "expression.hpp"
#include "environment.hpp"
#include "interpreter_semantic_error.hpp"

Expression Interpreter::token_to_ast(TokenSequenceType &tokens)
{
  Expression result;
  std::string token = tokens.front();
  tokens.pop_front();
  if (token == "(")
  {
    Atom atom;
    token_to_atom(tokens.front(), atom);
    tokens.pop_front();
    Expression temp = Expression(atom);
    while (tokens.front() != ")")
    {
      Expression tmp = token_to_ast(tokens);
      temp.tail.push_back(tmp);
    }
    tokens.pop_front();
    result = temp;
  }
  else
  {
    Atom atom;
    token_to_atom(token, atom);
    Expression temp = Expression(atom);
    result = temp;
  }
  return result;
}

bool Interpreter::parse(std::istream &expression) noexcept
{
  // return true if input is valid. otherwise, return false.
  int left_bracket = 0;
  int right_bracket = 0;
  int left_loc;
  TokenSequenceType tokens = tokenize(expression);
  for (size_t i = 0; i < tokens.size(); ++i)
  {
    if (tokens[i] == "(")
    {
      left_bracket++;
      left_loc = i;
    }
    else if (tokens[i] == ")")
    {
      right_bracket++;
      if (left_bracket < right_bracket)
      {
        return false;
      }
      if (left_loc == i - 1)
      {
        return false;
      }
    }
    if (tokens[i] != ")" && tokens[i] != "(")
    {
      Atom temp;
      bool check = token_to_atom(tokens[i], temp);
      if (!check)
      {
        return false;
      }
    }
    if (i != tokens.size() - 1 && left_bracket == right_bracket)
    {
      return false;
    }
  }
  if (right_bracket != left_bracket || right_bracket == 0)
  {
    return false;
  }

  ast = token_to_ast(tokens);
  return true;
};

Expression Interpreter::eval_private(Expression &exp){
  Expression result;
  if (exp.head.type == BooleanType || exp.head.type == NumberType){
    result = exp;
  }
  else if (exp.head.type == SymbolType){
    if (exp.tail.empty()){ //do something
    }
    else if (exp.head.value.sym_value == "if"){
      Expression temp = eval_private(exp.tail[0]);
      if (temp.head.type == BooleanType && exp.tail.size() == 3){
        if (temp == true){
          result = eval_private(exp.tail[1]);
        }
        else{
          result = eval_private(exp.tail[2]);
        }
      }
      else{
        throw InterpreterSemanticError("<expression1> does not result in a Boolean Atom!");
      }
    }
    else if (exp.head.value.sym_value == "define"){
      if (exp.tail[0].head.value.sym_value != "if" && exp.tail[0].head.value.sym_value != "define" && exp.tail[0].head.value.sym_value != "begin"){
        env.def_exp(eval_private(exp.tail[1]), exp.tail[0].head.value.sym_value);
      }
      else{
        throw InterpreterSemanticError("Wrong arguement after define");
      }
    }
    else if (exp.head.value.sym_value == "begin"){
      Expression afterbegin;
      for (std::size_t i = 0; i < exp.tail.size(); ++i){
        afterbegin = eval_private(exp.tail[i]);
      }
      return afterbegin;
    }
    else{
      if (env.run_pointer(exp.head.value.sym_value) != Procedure()){
        Procedure proc = env.run_pointer(exp.head.value.sym_value);
        std::vector<Atom> temp;
        for (int i = 0; i < exp.tail.size(); i++){
          temp.push_back(eval_private(exp.tail.at(i)).head);
        }
        result = proc(temp);
      }
      else{
        throw InterpreterSemanticError("The procedure is not defined");
      }
    }
  }
  return result;
}

Expression Interpreter::eval()
{
  return eval_private(ast);
}