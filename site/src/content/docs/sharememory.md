---
title: Shared Memory
description: Inter-process communication (IPC) using shared memory patterns.
---

Inter-process communication (IPC) using shared memory patterns.

## Contents

- **process1.cpp** - First process with shared memory access
- **process2.cpp** - Second process with shared memory access
- **CMakeLists.txt** - Build configuration
- **include/** - Header files

## Building

```bash
cd sharememory
cmake -B build -S .
cmake --build build
./build/process1.exe
./build/process2.exe
```

## Pattern

These examples demonstrate inter-process communication through shared memory, allowing multiple processes to access and modify the same memory region.
