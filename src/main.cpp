
#include <vector>
#include <iostream>

#include "demos.hpp"
#include "mnist/mnist_reader.hpp"

int print_mnist_picture(vector<uint8_t> picture)
{
    if (image.size() != 28 * 28) {
        std::cout << "unexpected number of pixels (" << image.size() << " instead of " << 28 * 28 <<
            "), terminating ..." << std::endl;
        return 1;
    }

    for (int row = 0; row < 28; row++) {
        for (int col = 0; col < 28; col++) {
            auto val = (int)image.at(row * 28 + col);
            if (val > 0) printf("%03d ", val);
            else printf("    ");
        }
        std::cout << std::endl;
    }

    return 0;
}

int main(int argc, char** argv)
{
    int err = 0;

    //run_perceptron_demo();
    //search_for_not_gate_demo();
    //run_sigmoid_neuron_demo();
    //convert_decimal_to_binary_demo();

    auto mnist_dataset = mnist::read_dataset("/Users/benjamin/Documents/data_sets/mnist/", 0, 0);

    std::cout << "training_images.size() = " << mnist_dataset.training_images.size() << std::endl;
    std::cout << "training_labels.size() = " << mnist_dataset.training_labels.size() << std::endl;
    std::cout << "test_images.size() = " << mnist_dataset.test_images.size() << std::endl;
    std::cout << "test_labels.size() = " << mnist_dataset.test_labels.size() << std::endl;

    std::cout << std::endl << (int)mnist_dataset.training_labels.at(1024) << std::endl << std::endl;

    auto image = mnist_dataset.training_images.at(1024);
    err = print_mnist_picture(image);

    return err;
}
