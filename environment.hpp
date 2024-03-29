#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

// system includes
#include <map>

// module includes
#include "expression.hpp"

class Environment
{
public:
  Environment();
  Procedure run_pointer(Symbol str);
  void def_exp(Expression exp, std::string str);



private:
  // Environment is a mapping from symbols to expressions or procedures
  enum EnvResultType
  {
    ExpressionType,
    ProcedureType
  };
  struct EnvResult
  {
    EnvResultType type;
    Expression exp;
    Procedure proc;
  };

  std::map<Symbol, EnvResult> envmap;
};

#endif
