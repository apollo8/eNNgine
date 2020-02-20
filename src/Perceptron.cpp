
#include "Perceptron.hpp"
#include "types.hpp"

/* constructor */
Perceptron::Perceptron(float threshold, vector<float> weights)
{
  if (weights.size() == 0) {
    throw std::runtime_error("weights cannot be an empty list");
  }

  this->threshold = threshold;
  this->weights = weights;
}

/* compute output */
int Perceptron::compute(vector<int> inputs)
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

