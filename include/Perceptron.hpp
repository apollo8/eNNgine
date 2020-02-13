
#ifndef PERCEPTRON_HPP
#define PERCEPTRON_HPP

#include <vector>

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
  short compute_output(std::vector<short> inputs);
};

#endif /* PERCEPTRON_HPP */

