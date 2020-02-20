
#include "SigmoidNeuron.hpp"
#include "demos.hpp"
#include "types.hpp"


void convert_decimal_to_binary_demo()
{
  /***
  b| 4 3 2 1
  ----------
  0: 0 0 0 0
  1: 0 0 0 1
  2: 0 0 1 0
  3: 0 0 1 1
  4: 0 1 0 0
  5: 0 1 0 1
  6: 0 1 1 0
  7: 0 1 1 1
  8: 1 0 0 0
  9: 1 0 0 1
  *///

  //  w * x    + b
  // 10 * 0.99 - 5 = +4.9
  // 00 * 0.99 - 5 = -5

  /*                    0   1   2   3   4   5   6   7   8   9 */
  SigmoidNeuron b1(-5, {0, 10,  0, 10,  0, 10,  0, 10,  0, 10});
  SigmoidNeuron b2(-5, {0,  0, 10, 10,  0,  0, 10, 10,  0,  0});
  SigmoidNeuron b3(-5, {0,  0,  0,  0, 10, 10, 10, 10,  0,  0});
  SigmoidNeuron b4(-5, {0,  0,  0,  0,  0,  0,  0,  0, 10, 10});

  // float-to-binary normalization
  auto normalize = [](float f){ return f > 0.5 ? 1 : 0; };

  vector<float> inputs {0.99, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001};
  std::cout << "0: " << normalize(b4.compute(inputs)) << normalize(b3.compute(inputs))
                     << normalize(b2.compute(inputs)) << normalize(b1.compute(inputs)) << std::endl;

  inputs = {0.001, 0.99, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001};
  std::cout << "1: " << normalize(b4.compute(inputs)) << normalize(b3.compute(inputs))
                     << normalize(b2.compute(inputs)) << normalize(b1.compute(inputs)) << std::endl;

  inputs = {0.001, 0.001, 0.99, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001};
  std::cout << "2: " << normalize(b4.compute(inputs)) << normalize(b3.compute(inputs))
                     << normalize(b2.compute(inputs)) << normalize(b1.compute(inputs)) << std::endl;

  inputs = {0.001, 0.001, 0.001, 0.99, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001};
  std::cout << "3: " << normalize(b4.compute(inputs)) << normalize(b3.compute(inputs))
                     << normalize(b2.compute(inputs)) << normalize(b1.compute(inputs)) << std::endl;

  inputs = {0.001, 0.001, 0.001, 0.001, 0.99, 0.001, 0.001, 0.001, 0.001, 0.001};
  std::cout << "4: " << normalize(b4.compute(inputs)) << normalize(b3.compute(inputs))
                     << normalize(b2.compute(inputs)) << normalize(b1.compute(inputs)) << std::endl;

  inputs = {0.001, 0.001, 0.001, 0.001, 0.001, 0.99, 0.001, 0.001, 0.001, 0.001};
  std::cout << "5: " << normalize(b4.compute(inputs)) << normalize(b3.compute(inputs))
                     << normalize(b2.compute(inputs)) << normalize(b1.compute(inputs)) << std::endl;

  inputs = {0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.99, 0.001, 0.001, 0.001};
  std::cout << "6: " << normalize(b4.compute(inputs)) << normalize(b3.compute(inputs))
                     << normalize(b2.compute(inputs)) << normalize(b1.compute(inputs)) << std::endl;

  inputs = {0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.99, 0.001, 0.001};
  std::cout << "7: " << normalize(b4.compute(inputs)) << normalize(b3.compute(inputs))
                     << normalize(b2.compute(inputs)) << normalize(b1.compute(inputs)) << std::endl;

  inputs = {0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.99, 0.001};
  std::cout << "8: " << normalize(b4.compute(inputs)) << normalize(b3.compute(inputs))
                     << normalize(b2.compute(inputs)) << normalize(b1.compute(inputs)) << std::endl;

  inputs = {0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.001, 0.99};
  std::cout << "9: " << normalize(b4.compute(inputs)) << normalize(b3.compute(inputs))
                     << normalize(b2.compute(inputs)) << normalize(b1.compute(inputs)) << std::endl;
}
