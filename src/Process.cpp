#include "Process.h"

#include <sstream>

process::process(std::stringstream ss) {
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

bool process::is_complete() const { return progress >= burst_time; }

int process::turnaround_length() const { return completion_time - arrival_time; }

int process::wait_length() const { return turnaround_length() - burst_time; }