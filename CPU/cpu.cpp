#include "cpu.hpp"

#include <atomic>
#include <thread>




void spin_lock(std::atomic<bool>& flag) {
	while (flag.exchange(true, std::memory_order_acquire)) {

#if defined(__x86_64__) || defined(_M_X64)
		__builtin_ia32_pause();
#elif defined(__aarch64__)
		asm volatile("yield" ::: "memory");
#else
		std::this_thread::yield();
#endif
	};
};

void write_hardware_register(uintptr_t base_address, uint32_t value) {

	auto* reg = reinterpret_cast<volatile uint32_t*>(base_address);

	*reg = value;
};