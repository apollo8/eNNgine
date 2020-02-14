
#include <vector>
#include <iostream>

#include "Perceptron.hpp"

void run_perceptron_demo()
{
  /* perceptron implementing OR gate */

  std::cout << "OR gate" << std::endl;
  Perceptron p_OR(0, {1, 1});

  std::cout << "{0, 0} -> " << p_OR.compute({0, 0}) << std::endl;
  std::cout << "{0, 1} -> " << p_OR.compute({0, 1}) << std::endl;
  std::cout << "{1, 0} -> " << p_OR.compute({1, 0}) << std::endl;
  std::cout << "{1, 1} -> " << p_OR.compute({1, 1}) << std::endl;

  /* perceptron implementing NOT gate */

  std::cout << std::endl << "NOT gate" << std::endl;
  Perceptron p_NOT(-1, {-1});

  std::cout << "{0} -> " << p_NOT.compute({0}) << std::endl;
  std::cout << "{1} -> " << p_NOT.compute({1}) << std::endl;

  /* multilayer perceptron implementing IMPLIES function */

  // IMPLIES(a, b) == OR(NOT(a), b)
  std::cout << std::endl << "IMPLIES function" << std::endl;

  std::cout << "0 -> 0 ? " << p_OR.compute({p_NOT.compute({0}), 0}) << std::endl;
  std::cout << "0 -> 1 ? " << p_OR.compute({p_NOT.compute({0}), 1}) << std::endl;
  std::cout << "1 -> 0 ? " << p_OR.compute({p_NOT.compute({1}), 0}) << std::endl;
  std::cout << "1 -> 1 ? " << p_OR.compute({p_NOT.compute({1}), 1}) << std::endl;
}

int main(int argc, char** argv)
{
  run_perceptron_demo();

  return 0;
}
