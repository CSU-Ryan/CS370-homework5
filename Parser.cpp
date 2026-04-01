#include "Parser.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

struct process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;

    explicit process(std::stringstream ss) {
        std::string placeholder;

        std::getline(ss, placeholder, ',');
        id = std::stoi(placeholder);

        std::getline(ss, placeholder, ',');
        arrival_time = std::stoi(placeholder);

        std::getline(ss, placeholder, ',');
        burst_time = std::stoi(placeholder);

        std::getline(ss, placeholder, ',');
        priority = std::stoi(placeholder);
    }
};

std::vector<process> parse(const std::string& input_filename) {
    auto processes = std::vector<process>();
    std::ifstream input{input_filename};

    if (!input.is_open()) {
        std::cerr << "Error opening input file" << std::endl;
        exit(-1);
    }

    for (std::string line; std::getline(input, line);) {
        std::stringstream ss{line};
        processes.emplace_back(std::move(ss));
    }

    return processes;
}
