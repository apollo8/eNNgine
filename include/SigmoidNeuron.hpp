
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

/* demo code */
void search_for_not_gate_demo();
void run_sigmoid_neuron_demo();

#endif /* SIGMOIDNEURON_HPP */

