#include "tokenize.hpp"
#include <cctype>

#include <iostream>

TokenSequenceType tokenize(std::istream &seq)
{
  TokenSequenceType tokens;

  char c;
  std::string temp;
  while (seq.get(c))
  {
    if (c == ' ')
    {
      if (!temp.empty())
      {
        tokens.emplace_back(temp);
        temp.clear();
      }
    }

    else if (c == '(' || c == ')' || c == ';' || c == '*' || c == '/' || c == '+' || c == '-')
    {
      if (!temp.empty())
      {
        tokens.emplace_back(temp);
        temp.clear();
        temp.push_back(c);
        tokens.emplace_back(temp);
        temp.clear();
      }
      else
      {
        temp.push_back(c);
        tokens.emplace_back(temp);
        temp.clear();
      }
    }
    else
    {
      temp.push_back(c);
    }
  }

  if(!temp.empty())
    {
        tokens.emplace_back(temp);
        temp.clear();
    }
  return tokens;
}
