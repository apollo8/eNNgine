
#ifndef SIGMOIDNEURON_HPP
#define SIGMOIDNEURON_HPP

#include <vector>
#include <iostream>

class SigmoidNeuron
{
private:
  /* attributes */
  std::vector<float> weights;
  float bias;

public:
  /* constructor */
  SigmoidNeuron(float bias, std::vector<float> weights);

  /* method: compute output */
  float compute(std::vector<float> inputs);
};

#endif /* SIGMOIDNEURON_HPP */

