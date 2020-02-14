
#include "Perceptron.hpp"

/* constructor */
Perceptron::Perceptron(float threshold, std::vector<float> weights)
{
  if (weights.size() == 0) {
    throw std::runtime_error("weights cannot be an empty list");
  }

  this->threshold = threshold;
  this->weights = weights;
}

/* compute output */
int Perceptron::compute(std::vector<int> inputs)
{
  /* validate input */

  if (inputs.size() != weights.size()) {
    throw std::runtime_error("wrong input size");
  }

  for (int i : inputs) {
    if (i != 0 && i != 1) {
      throw std::runtime_error("inputs must be binary");
    }
  }

  /* compute weighted sum */

  float weighted_sum = 0;

  for (size_t i = 0; i < inputs.size(); i++) {
    weighted_sum = weighted_sum + (inputs.at(i) * weights.at(i));
  }

  /* fire iff weighted sum exceeds threshold */

  return weighted_sum > threshold ? 1 : 0;
}

/* demo code */
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

  std::cout << std::endl << "IMPLIES function" << std::endl;

  auto implies = [&](int a, int b) {
    // IMPLIES(a, b) == OR(NOT(a), b)
    return p_OR.compute({p_NOT.compute({a}), b});
  };

  std::cout << "0 -> 0 ? " << implies(0, 0) << std::endl;
  std::cout << "0 -> 1 ? " << implies(0, 1) << std::endl;
  std::cout << "1 -> 0 ? " << implies(1, 0) << std::endl;
  std::cout << "1 -> 1 ? " << implies(1, 1) << std::endl;
}
