// ! Legend:
// ! TOT --> Total
// ! AVL --> Available
// ! AVG --> Average
// ! STD --> Standard

#include <iostream>
#include <thread>

#include "cpu.hpp"


int main() {
	CPU_DATA_STD cpu;

	unsigned int logicalCores_TOT = std::thread::hardware_concurrency();
	cpu.logicalCores_AVL = logicalCores_TOT;

	std::cout << "Available Logical CPU Cores: " << cpu.logicalCores_AVL;
	return 0;
};
