#include "BMPReader.h"
#include <iostream>
#include <fstream>

Picture Read(const std::string& path) {
    std::vector<unsigned char> header(54, 0);
    std::ifstream in_stream;
    in_stream.open(path, std::ios_base::binary | std::ios_base::in);
    if (in_stream.fail()) {
        throw std::runtime_error("Could not open the input file");
    }
    for (int i = 0; i < 54; i++) {
        in_stream.read(reinterpret_cast<char*>(&header[i]), 1);
    }
    size_t width = BytesToInt(header, 18, 4);
    size_t height = BytesToInt(header, 22, 4);
    std::vector<std::vector<Pixel>> matrix(height, std::vector<Pixel>(width));
    size_t paddings = (4 - (3 * width) % 4) % 4;

    for (size_t i = 0; i < (width * 3 + paddings) * height; i += 3) {
        unsigned char red = 0;
        unsigned char green = 0;
        unsigned char blue = 0;
        in_stream.read(reinterpret_cast<char *>(&red), 1);
        in_stream.read(reinterpret_cast<char *>(&green), 1);
        in_stream.read(reinterpret_cast<char *>(&blue), 1);
        matrix[i / (3 * width)][(i % (3 * width)) / 3] = Pixel(static_cast<double>(red) / 255,
                                                               static_cast<double>(green) / 255,
                                                               static_cast<double>(blue) / 255);
        if ((i + 1) % (width * 3) == 0) {
            unsigned char padding = 0;
            for (size_t u = 0; u < paddings; ++u) {
                in_stream.read(reinterpret_cast<char *>(padding), 1);
            }
        }
    }
    return {matrix, header};
}

uint32_t BytesToInt(const std::vector<unsigned char>& bytes, size_t index, size_t len) {
    uint32_t result = 0;
    uint32_t pow = 1;
    for (size_t i = index; i < index + len; ++i) {
        result += pow * static_cast<int32_t>(bytes[i]);
        pow *= 256;
    }
    return result;
}
