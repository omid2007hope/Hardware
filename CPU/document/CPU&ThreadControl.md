# CPU & Thread Execution Control

## x86 Assembly `PAUSE` Instruction

A special CPU instruction built into Intel/AMD processors. When called inside a spin loop:
- It reduces power and heat consumed by the CPU while spinning.
- It releases pipeline resources so a paired Hyper-Thread (SMT core) can run faster.
- It prevents CPU pipeline memory ordering stalls when exiting the loop.

## Yield Controls

- **Hardware `YIELD` (ARM64):** An assembly instruction that hints to the ARM CPU core to temporarily slow down instruction execution for this thread.
- **Software `std::this_thread::yield()`:** A C++ function that tells the Operating System scheduler: *"I am not doing critical work right now; give up my remaining CPU time slice to another waiting thread."*
