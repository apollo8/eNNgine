
#include <vector>
#include <iostream>

#include "Perceptron.hpp"

int main(int argc, char** argv)
{
  std::vector<float> weights {3, 5, 1.1};
  Perceptron p(0.5, weights);

  std::cout << p.compute_output({2, 2, 2}) << std::endl;

  return 0;
}
