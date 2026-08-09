# Memory Synchronization

Refers to computer **RAM** (and CPU cache hierarchies). 

In multi-threaded programs, multiple CPU cores read and write to the same memory locations simultaneously. Synchronizations like `spin_lock` ensure memory reads and writes stay orderly and free from data races or memory corruption.
