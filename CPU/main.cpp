#include <iostream>
#include <thread>

#include "CPU.hpp"

int main() {
  CPU_DATA cpu;

  unsigned int cores = std::thread::hardware_concurrency();
  cpu.cores = cores;

  std::cout << cpu.cores;
  return 0;
};
