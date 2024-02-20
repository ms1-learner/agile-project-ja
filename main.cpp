#include <iostream>

#include "math_operations.h"

float execute_calculation(float num1, char symbol, float num2)
{
  float out{0};
  try
  {
    if (symbol == '+')
    {
      out = MathOps::addition(num1, num2);
    }
    else if (symbol == '-')
    {
      out = MathOps::subtraction(num1, num2);
    }
    else if (symbol == '*')
    {
      out = MathOps::multiplication(num1, num2);
    }
    else if (symbol == '/')
    {
      out = MathOps::division(num1, num2);
    }
    else if (symbol == 'r')
    {
      out = MathOps::sqrtroot(num1);
    }
    else if (symbol == '^')
    {
      out = MathOps::exponentiation(num1, num2);
    }
    else
    {
      std::cout << "Input symbol is invalid. Exit calculation." << std::endl;
      exit(1);
    }
    std::cout << "Current Result: " << out << std::endl;
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    exit(1);
  }
  return out;
}

int main()
{
  float num1{0}, num2{0};
  char symbol{'a'};
  float current_result{0};

  std::cout << "Enter a calculation: ";
  std::cin >> num1 >> symbol >> num2;
  current_result = execute_calculation(num1, symbol, num2);

  while (1)
  {
    std::cout << "If you want to continue calculation for the current result '" << current_result
              << "', press 'c', if you want to exit, press 'e'." << std::endl;
    char next_action{'a'};
    std::cin >> next_action;
    if (next_action == 'c')
    {
      std::cout << "Please input the calculation symbol and number." << std::endl;
      std::cin >> symbol >> num2;
      current_result = execute_calculation(current_result, symbol, num2);
    }
    else if (next_action == 'e')
    {
      break;
    }
  }

  return 0;
}
