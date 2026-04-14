# Directory Structure
```
.
├── src
│   ├── Process            (.cpp & .h) [Struct for holding data of a process.]
│   ├── ProcessComparators (.h)        [Classes for comparing processes. 
│   │                                   Used to sort priority queues by different variables.]
│   ├── Parser             (.cpp & .h) [Creates processes from input csv file.]
│   ├── GeneralScheduler   (.h)        [Generalized CPU process scheduler for all three algorithms.]
│   └── Scheduler          (.cpp)      [Main file. 
│                                       Runs all three scheduling algorithms and prints statistics.]
├── Makefile  [Builds and cleans project]
└── README.md [This file]
```

# How to Run Project
Begin by running `$ make all`, which will compile all necessary files into `/build/` and `/bin/`. 
Then run `$ bin/Scheduler <csv-file>` to activate the scheduler, with path to csv file provided.
The project can be cleaned by running `$ make clean`.
