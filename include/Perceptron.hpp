
#ifndef PERCEPTRON_HPP
#define PERCEPTRON_HPP

#include <vector>
#include <iostream>

#include "types.hpp"

class Perceptron
{
private:
  /* attributes */
  vector<float> weights;
  float threshold;

public:
  /* constructor */
  Perceptron(float threshold, vector<float> weights);

  /* method: compute output */
  int compute(vector<int> inputs);
};

#endif /* PERCEPTRON_HPP */

