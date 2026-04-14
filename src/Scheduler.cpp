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

int main(const int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "ERROR: invalid number of arguments" << std::endl;
        return 1;
    }

    auto fcfs = GeneralScheduler<ArrivesFirst>(parse(argv[1]));
    fcfs.run();
    print_statistics("FCFS", fcfs.average_turnaround(), fcfs.average_wait(), fcfs.average_throughput());

    auto sjf = GeneralScheduler<ShortestFirst>(parse(argv[1]));
    sjf.run();
    print_statistics("SJFP", sjf.average_turnaround(), sjf.average_wait(), sjf.average_throughput());

    auto priority = GeneralScheduler<PriorityFirst>(parse(argv[1]));
    priority.run();
    print_statistics("Priority", priority.average_turnaround(), priority.average_wait(), priority.average_throughput());

}
