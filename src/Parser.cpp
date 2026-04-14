#include "Parser.h"
#include "Process.h"

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


std::vector<process*> parse(const std::string& input_filename) {
    auto processes = std::vector<process*>();
    std::ifstream input{input_filename};

    if (!input.is_open()) {
        std::cerr << "Error opening input file" << std::endl;
        exit(-1);
    }

    for (std::string line; std::getline(input, line);) {
        std::stringstream ss{line};
        processes.emplace_back(new process(std::move(ss)));
    }

    return processes;
}
