---
title: Concurrency
description: Concurrency and multithreading patterns in C++.
---

Concurrency and multithreading patterns in C++.

## Atomic Variable

Atomic variables (like `std::atomic<bool>`) ensure safe, lock-free access across threads.
They always hold exactly one consistent value at a time, even when multiple threads read/write to them.

Ideal for status flags:
- One-time init
- Stop signal
- Task completion signal

## Mutex

- `unique_lock` — only one thread can access the resource at a time
- `shared_lock` — usually for readers that don't modify resources
- `condition_variable` — used to avoid spurious wakeup (when no element in task queue, but resources still get locked)

## Detach

The thread continues to run in the background. The parent thread does not wait for it to finish (`join()` is never called). When the thread finishes, its resources are automatically cleaned up.

```cpp
t.detach();  // no join() needed
```
