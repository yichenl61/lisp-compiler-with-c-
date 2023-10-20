#include "expression.hpp"

// system includes
#include <sstream>
#include <cmath>
#include <limits>
#include <cctype>
#include <tuple>

Expression::Expression(bool tf)
{
  head.type = BooleanType;
  head.value.bool_value = tf;
}

Expression::Expression(double num)
{
  head.type = NumberType;
  head.value.num_value = num;
}

Expression::Expression(const std::string &sym)
{
  head.type = SymbolType;
  head.value.sym_value = sym;
}

Expression::Expression(std::tuple<double, double> value)
{
  head.type = PointType;
  head.value.point_value.x = std::get<0>(value);
  head.value.point_value.y = std::get<1>(value);
}

Expression::Expression(std::tuple<double, double> start,
                       std::tuple<double, double> end)
{
  head.type = LineType;
  head.value.line_value.first.x = std::get<0>(start);
  head.value.line_value.first.y = std::get<1>(start);

  head.value.line_value.second.x = std::get<0>(end);
  head.value.line_value.second.y = std::get<1>(end);
}

Expression::Expression(std::tuple<double, double> center,
                       std::tuple<double, double> start,
                       double angle)
{
  head.type = ArcType;
  head.value.arc_value.center.x = std::get<0>(center);
  head.value.arc_value.center.y = std::get<1>(center);

  head.value.arc_value.start.x = std::get<0>(start);
  head.value.arc_value.start.y = std::get<1>(start);

  head.value.arc_value.span = angle;
}

bool Expression::operator==(const Expression &exp) const noexcept
{
  // TODO: implement this function
  if (head.type == exp.head.type)
  {
    switch (head.type)
    {
    case BooleanType:
      if (head.value.bool_value == exp.head.value.bool_value && tail.size() == exp.tail.size())
      {
        return true;
      }
      break;
    case NumberType:
      if (head.value.num_value == exp.head.value.num_value && tail.size() == exp.tail.size())
      {
        return true;
      }
      break;
    case SymbolType:
      if (head.value.sym_value == exp.head.value.sym_value && tail.size() == exp.tail.size())
      {
        return true;
      }
      break;
    case NoneType:
      return true;
      break;
    default:
      return false;
      break;
    }
  }
}

std::ostream &operator<<(std::ostream &out, const Expression &exp)
{
  // TODO: implement this function
  return out;
}

bool token_to_atom(const std::string &token, Atom &atom)
{
  bool result = false;
  if (token == "True")
  {
    atom.type = BooleanType;
    atom.value.bool_value = true;
    result = true;
  }
  else if (token == "False")
  {
    atom.type = BooleanType;
    atom.value.bool_value = false;
    result = true;
  }
  else if (token[0] == '-' || token[0] == '+' || isdigit(token[0]) != 0)
  {
    if (token.size() == 1)
    {
      if (isdigit(token[0]) != 0)
      {
        atom.type = NumberType;
        atom.value.num_value = stod(token);
        result = true;
      }
      else
      {
        atom.type = SymbolType;
        atom.value.sym_value = token;
        result = true;
      }
    }
    else if (token.size() > 1)
    {
      for (std::size_t i = 1; i < token.size(); ++i)
      {
        if (isdigit(token[i]) == 0 && token[i] != 'e' && token[i] != '.')
        {
          return false;
        }
      }
      atom.type = NumberType;
      atom.value.num_value = stod(token);
      result = true;
    }
  }
  else
  {
    atom.type = SymbolType;
    atom.value.sym_value = token;
    result = true;
  }

  return result;
}

// bool numcheck(const std::string &str)
// {
//   if (str.size() > 1)
//   {
//     if (str[0] == '-' || isdigit(str[0] != 0))
//     {
//       for (std::size_t i = 1; i < str.size(); ++i)
//       {
//         if (isdigit(str[i] != 0) || str[i] == 'e' || str[i] == '.')
//         {
//           return true;
//         }
//         else
//         {
//           return false;
//         }
//       }
//     }
//     else
//     {
//       return false;
//     }
//   }
//   else
//   {
//     if (isdigit(str[0]))
//     {
//       return true;
//     }
//   }
// }
