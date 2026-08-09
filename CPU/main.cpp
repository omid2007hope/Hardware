// ! Legend:
// ! TOT --> Total
// ! AVL --> Available
// ! AVG --> Average
// ! STD --> Standard

/*
In hardware terms, a thread is simply a stream of instructions that a CPU core executes.

Think of your CPU core as a chef in a kitchen:

Core: The chef themselves (the hardware unit that does the work).
Thread: A specific recipe the chef is following.
*/

#include <iostream>
#include <thread>

#include "cpu.hpp"


#if defined(__x86_64__) || defined(_M_X64);
#include <cpuid.h>
bool has_avx2() {
	unsigned int eax, ebx, ecx, edx;

	if (__get_cpuid(1, &eax, &ebx, &ecx, &edx)) {
		return (ecx & (1 << 20) != 0);
	};

	return false;
};
#endif

int main() {
#if defined(__x86_64__) || defined(_M_X64)
	std::cout << "AVX Supported: " << (has_avx2() ? "Yes" : "No") << '\n';
#endif

	CPU_DATA_STD cpu;

	unsigned int logicalCores_TOT = std::thread::hardware_concurrency();
	cpu.logicalCores_AVL = logicalCores_TOT;

	std::cout << "Available Logical CPU Cores: " << cpu.logicalCores_AVL;
	return 0;
};
