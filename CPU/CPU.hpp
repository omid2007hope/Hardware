#include <atomic>
#include <new>

#ifndef CPU_DATA_HPP
#define CPU_DATA_HPP

/*
False Sharing Prevention: Using alignas(std::hardware_destructive_interference_size) ensures the struct starts at a memory address that is a multiple of the cache line size (typically 64 bytes on x86-64).  This prevents false sharing, where multiple threads modifying different variables in the same cache line cause performance degradation due to cache coherency traffic. 
Single Member Optimization: Since STANDARD_CPU_DATA contains only one member (counter), aligning the entire struct to the cache line size effectively isolates that atomic variable in its own cache line. This is ideal for scenarios where a single atomic variable is frequently updated by multiple threads.
Portable Constant: std::hardware_destructive_interference_size is a C++17 constant that provides a portable way to access the minimum recommended offset between concurrently accessed objects.  It is defined as a constexpr value, allowing its use in compile-time alignments like alignas.
Memory Overhead: The struct will likely be padded to fill at least one cache line (e.g., 64 bytes), even if the atomic counter itself is smaller (e.g., 8 bytes). This trade-off is standard to avoid the performance penalties of false sharing in concurrent programming. 
*/

struct alignas(std::hardware_destructive_interference_size) STANDARD_CPU_DATA {
  std::atomic<uint64_t> counter{0};

  int AvailableLogicalCores = 0; 
  
 };

#endif // CPU_DATA_HPP