# Mutex vs. Spinlock

## 1. Mutex (Mutual Exclusion)
An OS-managed lock. If Thread B tries to lock a mutex held by Thread A, the Operating System puts Thread B to **sleep** (a context switch). This frees the CPU core for other programs, but sleeping and waking up takes **thousands of CPU cycles**.

## 2. Spinlock
A thread-managed lock. If Thread B tries to lock a spinlock, it stays active in a tight loop (**spinning**) constantly checking if the lock is free. It avoids OS context-switching overhead, making it extremely fast for **tiny waits** (nanoseconds), but wasteful if waiting for a long time.
