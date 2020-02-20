
#ifndef SIGMOIDNEURON_HPP
#define SIGMOIDNEURON_HPP

#include <vector>
#include <iostream>

#include "types.hpp"

class SigmoidNeuron
{
private:
    /* attributes */
    vector<float> weights;
    float bias;

public:
    /* constructor */
    SigmoidNeuron(float bias, vector<float> weights);

    /* method: compute output */
    float compute(vector<float> inputs);
};

#endif /* SIGMOIDNEURON_HPP */

