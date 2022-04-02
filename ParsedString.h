#pragma once

#include <string>
#include <vector>
#include <utility>

class ParsedString {
public:
    ParsedString(int argc, char* argv[]);
    std::vector<std::pair<std::string, std::vector<double>>> GetFilters() const;
    std::string GetInputPath() const;
    std::string GetOutputPath() const;
private:
    std::vector<std::pair<std::string, std::vector<double>>> filters_;
    std::string input_path_;
    std::string output_path_;
};
