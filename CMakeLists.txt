cmake_minimum_required(VERSION 3.17)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(image_processor
        BMPStreams/BMPReader.cpp
        BMPStreams/BMPWriter.cpp
        image_processor.cpp
        FilterFactory.cpp
        filters/CropFilter.cpp
        filters/EdgeDetectionFilter.cpp
        filters/GaussianBlurFilter.cpp
        filters/GrayScaleFilter.cpp
        filters/MatrixFilter.cpp
        filters/NegativeFilter.cpp
        filters/SharpeningFilter.cpp
        filters/SquareFilter.cpp
        ParsedString.cpp
        Picture.cpp
        Pixel.cpp)
