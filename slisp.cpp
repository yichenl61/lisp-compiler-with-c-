#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include "interpreter.hpp"
#include "interpreter_semantic_error.hpp"

bool update1var()
{
  std::cout << "slisp> " << std::endl;
  std::string program;
  Interpreter interp;

  while (std::getline(std::cin, program))
  {
    std::istringstream iss(program);
    if (!interp.parse(iss))
    {
      std::cout << "parse error " << std::endl;
      return false;
    }
    try
    {
      Expression result = interp.eval();
      if (result.head.type == BooleanType)
      {
        if (result.head.value.bool_value)
        {
          std::cout << "(True)" << std::endl;
        }
        else
        {
          std::cout << "(False)" << std::endl;
        }
      }
      else if (result.head.type == NumberType)
      {
        std::cout << "(" << result.head.value.num_value << ")" << std::endl;
      }
      else if (result.head.type == PointType)
      {
        std::cout << "(" << result.head.value.point_value.x << "," << result.head.value.point_value.y << ")" << std::endl;
      }
      else if (result.head.type == LineType)
      {
        std::cout << "((" << result.head.value.line_value.first.x << "," << result.head.value.line_value.first.y << ")"
                  << ",(" << result.head.value.line_value.second.x << "," << result.head.value.line_value.second.y << "))" << std::endl;
      }
      else if (result.head.type == ArcType)
      {
        std::cout << "((" << result.head.value.arc_value.center.x << "," << result.head.value.arc_value.center.y << ")"
                  << ",(" << result.head.value.arc_value.start.x << "," << result.head.value.arc_value.start.y << "))"
                  << " " << result.head.value.arc_value.span << std::endl;
      }
      else
      {
        std::cout << "result type is wrong" << std::endl;
        return false;
      }
    }
    catch (InterpreterSemanticError &err)
    {
      std::cout << "error occurred when evaluating the program" << err.what() << std::endl;
      return false;
    }
    std::cout << "slisp> " << std::endl;
    return true;
  }
}

bool update2var(std::string program)
{
  std::ifstream readfile(program);
  if (!readfile)
  {
    std::cout << "could not open the file" << std::endl;
    return false;
  }
  Interpreter interp;
  if (!interp.parse(readfile))
  {
    std::cout << "parse error " << std::endl;
    return false;
  }
  try
  {
    Expression result = interp.eval();
    if (result.head.type == BooleanType)
    {
      if (result.head.value.bool_value)
      {
        std::cout << "(True)" << std::endl;
      }
      else
      {
        std::cout << "(False)" << std::endl;
      }
    }
    else if (result.head.type == NumberType)
    {
      std::cout << "(" << result.head.value.num_value << ")" << std::endl;
    }
    else if (result.head.type == PointType)
    {
      std::cout << "(" << result.head.value.point_value.x << "," << result.head.value.point_value.y << ")" << std::endl;
    }
    else if (result.head.type == LineType)
    {
      std::cout << "((" << result.head.value.line_value.first.x << "," << result.head.value.line_value.first.y << ")"
                << ",(" << result.head.value.line_value.second.x << "," << result.head.value.line_value.second.y << "))" << std::endl;
    }
    else if (result.head.type == ArcType)
    {
      std::cout << "((" << result.head.value.arc_value.center.x << "," << result.head.value.arc_value.center.y << ")"
                << ",(" << result.head.value.arc_value.start.x << "," << result.head.value.arc_value.start.y << "))"
                << " " << result.head.value.arc_value.span << std::endl;
    }
    else
    {
      std::cout << "result type is wrong" << std::endl;
      return false;
    }
  }
  catch (InterpreterSemanticError &err)
  {
    std::cout << "error occurred when evaluating the program" << err.what() << std::endl;
    return false;
  }
  return true;
}

bool update3var(std::string program)
{
  Interpreter interp;
  std::istringstream iss(program);
  if (!interp.parse(iss))
  {
    std::cout << "parse error " << std::endl;
    return false;
  }
  try
  {
    Expression result = interp.eval();
    if (result.head.type == BooleanType)
    {
      if (result.head.value.bool_value)
      {
        std::cout << "(True)" << std::endl;
      }
      else
      {
        std::cout << "(False)" << std::endl;
      }
    }
    else if (result.head.type == NumberType)
    {
      std::cout << "(" << result.head.value.num_value << ")" << std::endl;
    }
    else if (result.head.type == PointType)
    {
      std::cout << "(" << result.head.value.point_value.x << "," << result.head.value.point_value.y << ")" << std::endl;
    }
    else if (result.head.type == LineType)
    {
      std::cout << "((" << result.head.value.line_value.first.x << "," << result.head.value.line_value.first.y << ")"
                << ",(" << result.head.value.line_value.second.x << "," << result.head.value.line_value.second.y << "))" << std::endl;
    }
    else if (result.head.type == ArcType)
    {
      std::cout << "((" << result.head.value.arc_value.center.x << "," << result.head.value.arc_value.center.y << ")"
                << ",(" << result.head.value.arc_value.start.x << "," << result.head.value.arc_value.start.y << "))"
                << " " << result.head.value.arc_value.span << std::endl;
    }
    else
    {
      std::cout << "result type is wrong" << std::endl;
      return false;
    }
  }
  catch (InterpreterSemanticError &err)
  {
    std::cout << "error occurred when evaluating the program" << err.what() << std::endl;
    return false;
  }
  std::cout << "slisp> " << std::endl;
  return true;
}

int main(int argc, char **argv)
{
  switch (argc)
  {
  case 1:
  {
    if (update1var())
    {
      return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
    break;
  }
  case 2:
  {
    std::string temp = argv[1];
    if (update2var(temp))
    {
      return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
    break;
  }
  case 3:
  {
    if (strcmp(argv[1], "-e") != 0)
    {
      std::cout << "input format wrong" << std::endl;
      return EXIT_FAILURE;
    }
    std::string temp2 = argv[2];
    if (update3var(temp2))
    {
      return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
    break;
  }

  default:
  {
    std::cout << "wrong input" << std::endl;
    return EXIT_FAILURE;
    break;
  }
  }
}
