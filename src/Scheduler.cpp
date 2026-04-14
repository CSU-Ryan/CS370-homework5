#include <iostream>
#include <vector>

#include "ProcessComparators.h"
#include "Parser.h"
#include "GeneralScheduler.h"


void print_statistics(const std::string& type,
                     const double turnaround,
                     const double wait,
                     const double throughput) {
    std::printf("--- %s ---\n", type.c_str());
    std::printf("Average Turnaround Time: %.3f\n", turnaround);
    std::printf("Average Waiting Time: %.3f\n", wait);
    std::printf("Throughput: %.3f\n", throughput);
    std::printf("\n");
}

template <class Compare>
void run_scheduler(const char* file_path, const std::string& type) {
    auto s = GeneralScheduler<Compare>(parse(file_path));
    s.run();
    print_statistics(type,
        s.average_turnaround(),
        s.average_wait(),
        s.average_throughput());
}

/**
 * Only argument passed should be path to csv file
 */
int main(const int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "ERROR: invalid number of arguments" << std::endl;
        return 1;
    }

    run_scheduler<ArrivesFirst>(argv[1], "FCFS");
    run_scheduler<ShortestFirst>(argv[1], "SJFP");
    run_scheduler<PriorityFirst>(argv[1], "Priority");
}
