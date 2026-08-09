#include <iostream>
#include <thread>

#include "CPU.hpp"

int main() {
  STANDARD_CPU_DATA cpu;
  cpu.AvailableLogicalCores;

  

  unsigned int totalLogicalCores = std::thread::hardware_concurrency();
  cpu.AvailableLogicalCores = totalLogicalCores;

  std::cout << "Available Logical CPU Cores: " << cpu.AvailableLogicalCores;
  return 0;
};
