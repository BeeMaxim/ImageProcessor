#include "BMPStreams/BMPWriter.h"
#include "BMPStreams/BMPReader.h"
#include "FilterFactory.h"
#include "ParsedString.h"
#include <iostream>

void ProcessImage(int argc, char* argv[]) {
    std::vector<std::unique_ptr<Filter>> filters;
    FilterFactory factory;
    ParsedString arguments = ParsedString(argc, argv);
    for (auto& [type, params] : arguments.GetFilters()) {
        filters.push_back(factory.CreateFilter(type, params));
    }
    Picture image = Read(arguments.GetInputPath());
    for (const auto& filter: filters) {
        filter->Process(image);
    }
    Write(arguments.GetOutputPath(), image);
}

int main(int argc, char* argv[]) {
    try {
        if (argc > 1) {
            ProcessImage(argc, argv);
        } else {
            std::cout << "Arguments:\n"
                         "'-crop width height' - Crop filter\n"
                         "'-gs' - Grayscale filter\n"
                         "'-neg' - Negative filter\n"
                         "'-sharp' - Sharpening filter\n"
                         "'-edge threshold' - Edge Detection filter\n"
                         "'-blur sigma' - Gaussian Blur filter\n"
                         "'-square square_size' - Square filter\n";
        }
    } catch (const std::exception& e) {
        if (e.what()) {
            std::cerr << "Error: " << e.what() << std::endl;
        } else {
            std::cerr << "Error: something went wrong" << std::endl;
        }
    }
    return 0;
}

