# C++ Concurrency Standard Headers

- **`<atomic>` (`#include <atomic>`):** 
  Provides `std::atomic<T>` types (like `std::atomic<bool>`). Operations on atomic variables are thread-safe and indivisible (atomic)—meaning one CPU core cannot interrupt another core while it is reading or modifying an atomic variable.

- **`<thread>` (`#include <thread>`):** 
  Provides thread management features in C++, including launching threads (`std::thread`), sleeping (`std::this_thread::sleep_for`), or yielding execution time (`std::this_thread::yield()`).
