#include "environment.hpp"

#include <cassert>
#include <cmath>

#include "interpreter_semantic_error.hpp"

Expression logicalneg(const std::vector<Atom> &atoms)
{
  bool result;
  if (atoms.size() == 1)
  {
    if (atoms[0].type == BooleanType)
    {
      result = !atoms[0].value.bool_value;
    }
    else
    {
      throw InterpreterSemanticError("Arguments do not match (neg)");
    }
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (neg)");
  }
  return Expression(result);
}

Expression logicalconj(const std::vector<Atom> &atoms)
{
  bool result = true;
  if (!atoms.empty())
  {
    if (atoms[0].type == BooleanType)
    {
      for (std::size_t i = 0; i < atoms.size(); ++i)
      {
        if (!atoms[i].value.bool_value)
        {
          result = false;
        }
      }
    }
    else
    {
      throw InterpreterSemanticError("Arguments do not match (conj)");
    }
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (conj)");
  }
  return Expression(result);
}

Expression logicaldisj(const std::vector<Atom> &atoms)
{
  bool result = false;
  if (!atoms.empty())
  {
    if (atoms[0].type == BooleanType)
    {
      for (std::size_t i = 0; i < atoms.size(); ++i)
      {
        if (atoms[i].value.bool_value)
        {
          result = true;
        }
      }
    }
    else
    {
      throw InterpreterSemanticError("Arguments do not match (disj)");
    }
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (disj)");
  }
  return Expression(result);
}

Expression numless(const std::vector<Atom> &atoms)
{
  if (atoms.size() == 2)
  {
    if (atoms[0].type != NumberType)
    {
      throw InterpreterSemanticError("Arguments do not match (less)");
    }
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (less)");
  }
  if (atoms[0].value.num_value < atoms[1].value.num_value)
  {
    return Expression(true);
  }
  return Expression(false);
}

Expression numlesseq(const std::vector<Atom> &atoms)
{
  bool result;
  if (atoms.size() == 2)
  {
    if (atoms[0].type != NumberType)
    {
      throw InterpreterSemanticError("Arguments do not match (lesseq)");
    }
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (lesseq)");
  }
  if (atoms[0].value.num_value <= atoms[1].value.num_value)
  {
    return Expression(true);
  }

  return Expression(false);
}

Expression numgreater(const std::vector<Atom> &atoms)
{
  bool result;
  if (atoms.size() == 2)
  {
    if (atoms[0].type != NumberType)
    {
      throw InterpreterSemanticError("Arguments do not match (greater)");
    }
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (greater)");
  }

  if (atoms[0].value.num_value > atoms[1].value.num_value)
  {
    return Expression(true);
  }

  return Expression(false);
}

Expression numgreatereq(const std::vector<Atom> &atoms)
{
  bool result;
  if (atoms.size() == 2)
  {
    if (atoms[0].type != NumberType)
    {
      throw InterpreterSemanticError("Arguments do not match (greatereq)");
    }
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (greatereq)");
  }

  if (atoms[0].value.num_value >= atoms[1].value.num_value)
  {
    return Expression(true);
  }
  return Expression(false);
}

Expression equal(const std::vector<Atom> &atoms)
{
  bool result;
  if (atoms.size() == 2)
  {
    if (atoms[0].type != NumberType)
    {
      throw InterpreterSemanticError("Arguments do not match (eq,type)");
    }
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (eq)");
  }
  if (atoms[0].value.num_value == atoms[1].value.num_value)
  {
    return Expression(true);
  }
  return Expression(false);
}

Expression sum(const std::vector<Atom> &atoms)
{
  double result = 0.0;
  if (atoms.size() >= 2)
  {
    for (std::size_t i = 0; i < atoms.size(); ++i)
    {
      result += atoms[i].value.num_value;
    }
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (sum)");
  }
  return Expression(result);
}

Expression minus(const std::vector<Atom> &atoms)
{
  double result = 0.0;
  if (atoms[0].type == NumberType)
  {
    if (atoms.size() == 1)
    {
      result = -(atoms[0].value.num_value);
    }
    else if (atoms.size() == 2)
    {
      result = atoms[0].value.num_value - atoms[1].value.num_value;
    }
    else
    {
      throw InterpreterSemanticError("Arguments do not match (minus)");
    }
  }

  return Expression(result);
}

Expression product(const std::vector<Atom> &atoms)
{
  double result = 0.0;
  if (atoms.size() >= 2)
  {
    if (atoms[0].type == NumberType)
    {
      for (std::size_t i = 0; i < atoms.size(); ++i)
      {
        result *= atoms[i].value.num_value;
      }
    }
    else
    {
      throw InterpreterSemanticError("Arguments do not match (product)");
    }
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (product)");
  }
  return Expression(result);
}

Expression divide(const std::vector<Atom> &atoms)
{
  double result = 0.0;
  if (atoms[0].type == NumberType)
  {
    if (atoms.size() == 2)
    {
      result = atoms[0].value.num_value / atoms[1].value.num_value;
    }
    else
    {
      throw InterpreterSemanticError("Arguments do not match (div)");
    }
  }
  return Expression(result);
}

Expression log_10(const std::vector<Atom> &atoms)
{
  double result = 0.0;
  if (atoms[0].type == NumberType)
  {
    if (atoms.size() == 1)
    {
      result = log10(atoms[0].value.num_value);
    }
    else
    {
      throw InterpreterSemanticError("Arguments do not match (log_10)");
    }
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (log_10)");
  }
  return Expression(result);
}

Expression power(const std::vector<Atom> &atoms)
{
  double result = 0.0;
  if (atoms[0].type == NumberType)
  {
    if (atoms.size() == 2)
    {
      result = pow(atoms[0].value.num_value, atoms[1].value.num_value);
    }
    else
    {
      throw InterpreterSemanticError("Arguments do not match (div)");
    }
  }
  return Expression(result);
}

Expression sin_(const std::vector<Atom> &atoms)
{
  double result = 0.0;

  if (atoms.size() == 1)
  {
    result = sin(atoms[0].value.num_value);
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (sin)");
  }
  return Expression(result);
}

Expression cos_(const std::vector<Atom> &atoms)
{
  double result = 0.0;

  if (atoms.size() == 1)
  {
    result = cos(atoms[0].value.num_value);
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (cos)");
  }
  return Expression(result);
}

Expression arctan_(const std::vector<Atom> &atoms)
{
  double result = 0.0;

  if (atoms.size() == 2)
  {
    result = atan2(atoms[0].value.num_value, atoms[1].value.num_value);
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (arctan)");
  }
  return Expression(result);
}

Expression createpoint(const std::vector<Atom> &atoms)
{
  std::tuple<double, double> result;

  if (atoms.size() == 2)
  {
    result = std::make_tuple(atoms[0].value.num_value, atoms[1].value.num_value);
  }
  else
  {
    throw InterpreterSemanticError("Arguments do not match (cpoint)");
  }
  return Expression(result);
}

Expression createline(const std::vector<Atom> &atoms)
{
  if (atoms.size() != 2)
  {
    throw InterpreterSemanticError("Arguments do not match (cline)");
  }
  std::tuple<double, double> start = std::make_tuple(atoms[0].value.point_value.x, atoms[0].value.point_value.y);
  std::tuple<double, double> end = std::make_tuple(atoms[1].value.point_value.x, atoms[1].value.point_value.y);
  return Expression(start, end);
}

Expression createarc(const std::vector<Atom> &atoms)
{
  if (atoms.size() != 3)
  {
    throw InterpreterSemanticError("Arguments do not match (carc)");
  }
  std::tuple<double, double> center = std::make_tuple(atoms[0].value.point_value.x, atoms[0].value.point_value.y);
  std::tuple<double, double> start = std::make_tuple(atoms[1].value.point_value.x, atoms[1].value.point_value.y);
  double span = atoms[2].value.num_value;
  return Expression(start, center, span);
}

Procedure Environment::run_pointer(Symbol str)
{
  return envmap[str].proc;
}

void Environment::def_exp(Expression exp, std::string str)
{
  // for(std::size_t i = 0; i < envmap.size(); ++i)
  // {

  // }
  auto search = envmap.find(str);
  if (search != envmap.end())
  {
    throw InterpreterSemanticError("Argument has already been defined.");
  }
  envmap[str].type = ExpressionType;
  envmap[str].exp = exp;
}

Environment::Environment()
{
  // TODO: implement your code ...

  envmap["not"].type = ProcedureType;
  envmap["and"].type = ProcedureType;
  envmap["or"].type = ProcedureType;
  envmap["<"].type = ProcedureType;
  envmap["<="].type = ProcedureType;
  envmap[">"].type = ProcedureType;
  envmap[">="].type = ProcedureType;
  envmap["="].type = ProcedureType;
  envmap["+"].type = ProcedureType;
  envmap["-"].type = ProcedureType;
  envmap["*"].type = ProcedureType;
  envmap["/"].type = ProcedureType;
  envmap["log10"].type = ProcedureType;
  envmap["pow"].type = ProcedureType;
  envmap["pi"].type = ExpressionType;
  envmap["sin"].type = ProcedureType;
  envmap["cos"].type = ProcedureType;
  envmap["arctan"].type = ProcedureType;
  envmap["point"].type = ProcedureType;
  envmap["line"].type = ProcedureType;
  envmap["arc"].type = ProcedureType;

  envmap["not"].proc = &logicalneg;
  envmap["and"].proc = &logicalconj;
  envmap["or"].proc = &logicaldisj;
  envmap["<"].proc = &numless;
  envmap["<="].proc = &numlesseq;
  envmap[">"].proc = &numgreater;
  envmap[">="].proc = &numgreatereq;
  envmap["="].proc = &equal;
  envmap["+"].proc = &sum;
  envmap["-"].proc = &minus;
  envmap["*"].proc = &product;
  envmap["/"].proc = &divide;
  envmap["log10"].proc = &log_10;
  envmap["pow"].proc = &power;
  envmap["pi"].exp = atan2(0, -1);
  envmap["sin"].proc = &sin_;
  envmap["cos"].proc = &cos_;
  envmap["arctan"].proc = &arctan_;
  envmap["point"].proc = &createpoint;
  envmap["line"].proc = &createline;
  envmap["arc"].proc = &createarc;
}
