
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
short Perceptron::compute_output(std::vector<short> inputs)
{
  if (inputs.size() != weights.size()) {
    throw std::runtime_error("wrong input size");
  }

  float weighted_sum = 0;

  for (size_t i = 0; i < inputs.size(); i++) {
    weighted_sum = weighted_sum + (inputs.at(i) * weights.at(i));
  }

  return weighted_sum > threshold ? 1 : 0;
}

