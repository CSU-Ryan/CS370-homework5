#ifndef HW5_GENERALSCHEDULER_H
#define HW5_GENERALSCHEDULER_H

#include <queue>
#include <vector>

#include "Process.h"
#include "ProcessComparators.h"


template <class Compare>
class GeneralScheduler {
    // The artificial timer governing when processes arrive and when they complete.
    int timer;

    std::priority_queue<process*, std::vector<process*>, ArrivesFirst> upcoming_processes;
    std::priority_queue<process*, std::vector<process*>, Compare> ready_queue;
    /*
    These priority queues organize the processes into which is to be served next.
    For `upcoming_processes`, it is simply organized by arrival time (`ArrivesFirst`).
    For `ready_queue`, once processes have arrived, they are sorted by the generic `Compare`.
    In FCFS, the Compare is ArrivesFirst, in a priority scheduler, the Compare is PriorityFirst.
     */
    std::vector<process*> complete_processes;


    void queue_ready_processes() {
        while (!upcoming_processes.empty() && upcoming_processes.top()->arrival_time <= timer) {
            ready_queue.push(upcoming_processes.top());
            upcoming_processes.pop();
        }
    }

    void run_next_process() {
        if (ready_queue.empty()) return;

        process *active = ready_queue.top();
        ++active->progress;

        if (active->is_complete()) {
            active->completion_time = timer + 1;
            complete_processes.push_back(active);
            ready_queue.pop();
        }
    }


public:
    explicit GeneralScheduler(const std::vector<process*> &processes)
            : upcoming_processes(processes.begin(), processes.end()) {
        timer = upcoming_processes.top()->arrival_time - 1;
    }

    ~GeneralScheduler() {
        while (!upcoming_processes.empty()) {
            delete upcoming_processes.top();
            upcoming_processes.pop();
        };

        while (!ready_queue.empty()) {
            delete ready_queue.top();
            ready_queue.pop();
        };

        for (const auto& process : complete_processes) delete process;
    }

    void run() {
        while (!upcoming_processes.empty() || !ready_queue.empty()) {
            queue_ready_processes();
            run_next_process();
            ++timer;
        }
    }

    [[nodiscard]] double average_wait() const {
        double total_wait = 0;
        for (const auto& process : complete_processes) {
            total_wait += process->wait_length();
        }

        return total_wait / static_cast<double>(complete_processes.size());
    }

    [[nodiscard]] double average_turnaround() const {
        double total_turnaround = 0;
        for (const auto& process : complete_processes) {
            total_turnaround += process->turnaround_length();
        }

        return total_turnaround / static_cast<double>(complete_processes.size());
    }

    [[nodiscard]] double average_throughput() const {
        return static_cast<double> (complete_processes.size()) / timer;
    }
};


#endif //HW5_GENERALSCHEDULER_H
