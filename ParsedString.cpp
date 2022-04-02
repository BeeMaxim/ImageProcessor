#include "ParsedString.h"
#include <stdexcept>

ParsedString::ParsedString(int argc, char* argv[]) {
    if (argc == 1) {
        throw std::logic_error("output path is required");
    }
    input_path_ = argv[1];
    output_path_ = argv[2];
    for (int index = 3; index < argc; ++index) {
        try {
            double argument = std::stod(argv[index]);
            filters_.back().second.push_back(argument);
        } catch (const std::invalid_argument&) {
            filters_.push_back({argv[index], {}});
        }
    }
}

std::vector<std::pair<std::string, std::vector<double>>> ParsedString::GetFilters() const {
    return filters_;
}

std::string ParsedString::GetInputPath() const {
    return input_path_;
}

std::string ParsedString::GetOutputPath() const {
    return output_path_;
}
