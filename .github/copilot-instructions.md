# Copilot Instructions for TriviaCode

## Repository Overview
**triviaCode** is a multi-language educational codebase showcasing patterns across C/C++, Python, MATLAB, PowerShell, and Svelte. Each directory contains focused examples of specific domains rather than an integrated application.

## Key Architecture & Patterns

### 1. **Multi-Module Organization**
- **algorithm/**: Core data structure implementations (DSU, KMP, Dijkstra, DP problems, hashtables)
  - Structured by domain: `array/`, `dynamicprogram/`, `hashtable/`, `topoprogram/`, `linkednode/`
  - Standalone compilable files using `g++.exe` (via VS Code task)
- **concurrency/**: Multi-threading demos with Boost, condition variables, atomic operations
  - Uses `CMAKE` for builds; see `concurrency/CMakeLists.txt`
- **Svelte**: Modern reactive UI framework (SvelteKit) with runes (`$state`, `$derived`, `$effect`)
- **testautomation/**: Unit test patterns using pytest with mocking; API testing workflows

### 2. **Build & Compilation**
- **C/C++ Single Files**: Use VS Code's default build task
  - Command: `g++.exe -fdiagnostics-color=always -g ${file} -o ${fileDirname}\${fileBasenameNoExtension}.exe`
  - Output: `.exe` in same directory as source
- **CMake Projects** (concurrency, sharememory, dVRK_Qt):
  - Set CMake source dir: `cmake.sourceDirectory` in `.vscode/settings.json`
  - Example: `concurrency/CMakeLists.txt` configures Boost dependencies and multiple executables
  - Link external libs explicitly: `target_link_libraries(target PRIVATE Boost::thread)`
- **Svelte**: Use `npm run dev` for development; see `svelte/README.md`

### 3. **Threading & Concurrency Patterns**
- **std::atomic** for lock-free status flags (init signals, stop conditions)
- **mutex + condition_variable**: See `concurrency/README.md` diagram
  - Pattern: `unique_lock` for exclusive access, `shared_lock` for read-only
  - Always use predicate function with `cv.wait()` to prevent spurious wakeups
- **thread::detach()** leaves thread running; no join() required (use cautiously for cleanup)

### 4. **Python Testing Patterns**
- **Unit Tests** (`testautomation/unittest_demo.py`):
  - Use `@pytest.fixture` for setup/teardown
  - Mock external calls with `@patch("module.function")` to isolate logic
  - Test password generation, database saves independently via mocks
- **API Tests**:
  - HTTP requests to validate server endpoints
  - Compare response data with expected schema
- **Execution**: `pytest -s .\unittest_demo.py` (verbose output)

### 5. **Svelte 5+ Reactivity (SvelteKit)**
- **$state**: Reactive variables; declare inline: `let count = $state(0)`
- **$derived**: Computed values (synchronous)
- **$derived.by()**: Custom computed logic (deferred to microtask)
- **$effect** vs **$effect.pre**:
  - `$effect.pre`: Runs *before* DOM updates (ref elements undefined)
  - `$effect`: Runs *after* DOM updates (safe to access refs)
- **onMount/onDestroy**: Lifecycle hooks (return function for cleanup)
- **tick()**: Waits for next DOM update; use in effects for correct ref timing

### 6. **Qt Desktop Applications (dVRK_Qt)**
- Architecture: QApplication → QWidget tabs (ECM, PSM) → cisst logic + ROS bridge
- Subsystems wrapped as QtWidgets; main console configurable via JSON
- Connect to hardware via mtsIntuitiveResearchKitConsole

## Critical Developer Workflows

### Building & Running
1. **Single C++ file**: `Ctrl+Shift+B` (VS Code default task)
2. **CMake project** (e.g., concurrency):
   ```bash
   cd concurrency
   cmake -B build -S .
   cmake --build build
   ./build/threaddemo.exe  # or boostdemo, workerconsumer, etc.
   ```
3. **Svelte dev server**: `npm install && npm run dev` (opens http://localhost:5173)
4. **Python tests**: `pytest -s path/to/test.py`

### Common Issues & Solutions
- **Algorithm compilation fails**: Ensure `-g` flag for debugging; use `${fileDirname}` for relative paths
- **CMake find_package fails**: Install dependency (e.g., `Boost`); update `cmake.sourceDirectory` in settings
- **Svelte changes not hot-reloading**: Check that dev server is running; clear `.svelte-kit/` cache
- **Test mocks not working**: Import path in `@patch` must match module import; use full dotted path

## Project-Specific Conventions

- **No monolithic main()**: Each file is typically standalone or example-driven
- **Naming**: Snake_case for C++/Python; PascalCase for Qt classes
- **Comments**: Use `// ` for inline; document complex logic (DSU, threading patterns)
- **File organization**: Group related items in subdirectories (e.g., `algorithm/array/`, `dVRK_Qt/Qt/`)

## Key Files by Use Case
- **Learn concurrency**: `concurrency/README.md`, `thread_demo.cpp`, `worker_consumer.cpp`
- **Algorithm reference**: `algorithm/topoprogram/dijkstra.cpp`, `hashtable/hashtable.cpp`
- **Testing patterns**: `testautomation/unittest_demo.py`, `unittest_object.py`
- **Modern web UI**: `svelte/src/lib/component/randomNumber.svelte`
- **Qt GUI patterns**: `dVRK_Qt/Qt/robotGUIQt.cpp`
