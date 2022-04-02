#include "FilterFactory.h"
#include "filters/CropFilter.h"
#include "filters/GrayScaleFilter.h"
#include "filters/NegativeFilter.h"
#include "filters/SharpeningFilter.h"
#include "filters/EdgeDetectionFilter.h"
#include "filters/GaussianBlurFilter.h"
#include "filters/SquareFilter.h"
#include <stdexcept>
#include <memory>
#include <math.h>

std::unique_ptr<Filter> FilterFactory::CreateFilter(const std::string& type, const std::vector<double>& params) {
    if (type == "-crop") {
        if (params.size() == 2) {
            size_t width = std::round(params[0]);
            size_t height = std::round(params[1]);
            return std::make_unique<CropFilter>(width, height);
        } else {
            throw std::logic_error("-crop filter has invalid arguments, 2 numbers are required");
        }
    } else if (type == "-gs") {
        if (params.empty()) {
            return std::make_unique<GrayScaleFilter>();
        } else {
            throw std::logic_error("-gs filter has invalid arguments, 0 numbers are required");
        }
    } else if (type == "-neg") {
        if (params.empty()) {
            return std::make_unique<NegativeFilter>();
        } else {
            throw std::logic_error("-neg filter has invalid arguments, 0 numbers are required");
        }
    } else if (type == "-sharp") {
        if (params.empty()) {
            return std::make_unique<SharpeningFilter>();
        } else {
            throw std::logic_error("-sharp filter has invalid arguments, 0 numbers are required");
        }
    } else if (type == "-edge") {
        if (params.size() == 1) {
            double threshold = params[0];
            return std::make_unique<EdgeDetectionFilter>(threshold);
        } else {
            throw std::logic_error("-edge filter has invalid arguments, 1 number is required");
        }
    } else if (type == "-blur") {
        if (params.size() == 1) {
            double sigma = params[0];
            return std::make_unique<GaussianBlurFilter>(sigma);
        } else {
            throw std::logic_error("-blur filter has invalid arguments, 1 number is required");
        }
    } else if (type == "-square") {
        if (params.size() == 1) {
            size_t square_size = std::round(params[0]);
            return std::make_unique<SquareFilter>(square_size);
        } else {
            throw std::logic_error("-square filter has invalid arguments, 1 number is required");
        }
    } else {
        throw std::logic_error("Unknown filter name: " + type);
    }
}
