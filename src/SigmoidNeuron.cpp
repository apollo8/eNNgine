
#include <cmath>

#include "SigmoidNeuron.hpp"
#include "types.hpp"

/* constructor */
SigmoidNeuron::SigmoidNeuron(float bias, vector<float> weights)
{
  if (weights.size() == 0) {
    throw std::runtime_error("weights cannot be an empty list");
  }

  this->bias = bias;
  this->weights = weights;
}

/* compute output */
float SigmoidNeuron::compute(vector<float> inputs)
{
  /* validate input */

  if (inputs.size() != weights.size()) {
    throw std::runtime_error("wrong input size");
  }

  for (float f : inputs) {
    if (f < 0 || f > 1) {
      throw std::runtime_error("inputs must be between 0 and 1");
    }
  }

  /* compute weighted sum */

  float weighted_sum = 0;

  for (size_t i = 0; i < inputs.size(); i++) {
    weighted_sum = weighted_sum + (inputs.at(i) * weights.at(i));
  }

  /* fire iff weighted sum exceeds threshold */

  return (1 / (1 + std::exp(-(weighted_sum + bias))));
}

