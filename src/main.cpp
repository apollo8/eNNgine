
#include <vector>
#include <iostream>

#include "demos.hpp"
#include "mnist_helpers.hpp"


int main(int argc, char** argv)
{
    //run_perceptron_demo();
    //search_for_not_gate_demo();
    //run_sigmoid_neuron_demo();
    //convert_decimal_to_binary_demo();

    auto images = read_mnist_images("/Users/benjamin/Documents/data_sets/mnist/train-images-idx3-ubyte");

    std::cout << "#images: " << images.size() << std::endl;

    return 0;
}
