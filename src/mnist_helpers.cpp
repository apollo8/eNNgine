
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>

#include "mnist_helpers.hpp"
#include "types.hpp"

/***
The following two functions help to read the mnist data.
Adapted from https://stackoverflow.com/questions/8286668/how-to-read-mnist-data-in-c
*///

int reverseInt (const int i) 
{
    uchar c1, c2, c3, c4;

    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;

    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

vector<vector<uchar>> read_mnist_images(const char* full_path)
{
    vector<vector<uchar>> set_images;

    int magic_number = 0;
    int number_of_images = 0;
    int n_rows = 0;
    int n_cols = 0;

    std::ifstream file(full_path, std::ios::binary);

    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open MNIST file.");
    }

    file.read((char*)&magic_number, sizeof(magic_number)); 
    magic_number = reverseInt(magic_number);

    file.read((char*)&number_of_images, sizeof(number_of_images));
    number_of_images = reverseInt(number_of_images);
    set_images.reserve(number_of_images);

    file.read((char*)&n_rows, sizeof(n_rows));
    n_rows = reverseInt(n_rows);

    file.read((char*)&n_cols, sizeof(n_cols));
    n_cols = reverseInt(n_cols);

    for (int i = 0; i < number_of_images; ++i) {
        vector<uchar> current_image;
        current_image.reserve(n_rows * n_cols);

        for (int r = 0; r < n_rows; ++r) {
            for (int c = 0; c < n_cols; ++c) {
                uchar temp = 0;
                file.read((char*)&temp, sizeof(temp));
                current_image[(r*n_cols)+c] = temp;
            }
        }

        set_images.push_back(current_image);
    }
    
    return set_images;
}

