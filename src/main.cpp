
#include <vector>
#include <iostream>

#include "demos.hpp"
#include "mnist/mnist_reader.hpp"


int main(int argc, char** argv)
{
    //run_perceptron_demo();
    //search_for_not_gate_demo();
    //run_sigmoid_neuron_demo();
    //convert_decimal_to_binary_demo();

    auto mnist_dataset = mnist::read_dataset("/Users/benjamin/Documents/data_sets/mnist/", 0, 0);

    std::cout << "training_images.size() = " << mnist_dataset.training_images.size() << std::endl;
    std::cout << "training_labels.size() = " << mnist_dataset.training_labels.size() << std::endl;
    std::cout << "test_images.size() = " << mnist_dataset.test_images.size() << std::endl;
    std::cout << "test_labels.size() = " << mnist_dataset.test_labels.size() << std::endl;

    return 0;
}
