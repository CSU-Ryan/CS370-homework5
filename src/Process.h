#ifndef HW5_PROCESS_H
#define HW5_PROCESS_H

#include <iosfwd>

struct process {
    int id;
    int arrival_time;
    int burst_time;
    int progress = 0;
    int priority;
    int completion_time = -1;
    [[nodiscard]]
    bool is_complete() const;

    explicit process(std::stringstream ss);

    [[nodiscard]] int turnaround_length() const;
    [[nodiscard]] int wait_length() const;
};


#endif //HW5_PROCESS_H
