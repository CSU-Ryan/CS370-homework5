//
// Collection of classes with comparators. Used to sort priority queues.
//

#ifndef HW5_PROCESSCOMPARATORS_H
#define HW5_PROCESSCOMPARATORS_H

#include "Process.h"


class ArrivesFirst {
public:
    bool operator()(const process *a, const process *b) const {
        return a->arrival_time > b->arrival_time;
    }
};

class ShortestFirst {
public:
    bool operator()(const process *a, const process *b) const {
        return a->burst_time > b->burst_time;
    }
};

class PriorityFirst {
public:
    bool operator()(const process *a, const process *b) const {
        return a->priority > b->priority;
    }
};


#endif //HW5_PROCESSCOMPARATORS_H
