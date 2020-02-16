
#ifndef PERCEPTRON_HPP
#define PERCEPTRON_HPP

#include <vector>
#include <iostream>

class Perceptron
{
private:
  /* attributes */
  std::vector<float> weights;
  float threshold;

public:
  /* constructor */
  Perceptron(float threshold, std::vector<float> weights);

  /* method: compute output */
  int compute(std::vector<int> inputs);
};

#endif /* PERCEPTRON_HPP */

