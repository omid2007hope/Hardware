#include "cpu.hpp"

#include <atomic>
#include <thread>



void spin_lock(std::atomic<bool>& flag) {
	while (flag.exchange(true, std::memory_order_acquired)) {

#if defined(__x86_64__) || defined(_M_X64) __builtin_ia32_pause();

#elif defined(__aarch64__) asm volatile("yield" :: : "memory");

#else
		std::this_thread::yield();
#endif
	};
};
