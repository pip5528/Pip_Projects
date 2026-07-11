# Agent Guidelines for codecrafters-interpreter-c

This document outlines essential information for AI agents working in this codebase, including commands, code organization, and conventions.

## Project Type

This is a C project built with CMake and managed with vcpkg for dependencies. It targets the C23 standard.

## Essential Commands

### Build

To build the project, navigate to the root directory and run:

```bash
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake
cmake --build ./build
```

This will compile the source files and create the `interpreter` executable in the `build/` directory.

### Run

To run the compiled program:

```bash
./build/interpreter
```

You can pass arguments to the program like so:

```bash
./build/interpreter arg1 arg2
```

## Code Organization

- **`src/`**: Contains all C source (`.c`) and header (`.h`) files.
- **`build/`**: This directory is created by CMake and contains the compiled executable and other build artifacts. It should generally be ignored in version control.
- **`your_program.sh`**: A helper script to build and run the program locally.
- **`CMakeLists.txt`**: Defines the project's build process using CMake.
- **`vcpkg.json`**: Defines project dependencies managed by vcpkg.
- **`codecrafters.yml`**: CodeCrafters specific configuration.

## Naming Conventions and Style Patterns

- C-style naming conventions are used (e.g., `snake_case` for functions and variables).
- Header guards typically follow the `_H_` convention (e.g., `MY_MODULE_H_`).
- Refer to existing C files in the `src/` directory for specific formatting and style.

## Testing Approach

The project is likely tested through the CodeCrafters platform. Local testing would involve running the compiled `interpreter` executable with various inputs and verifying the output. There are no explicit unit testing frameworks configured in the provided files.

## Important Gotchas or Non-Obvious Patterns

- **Vcpkg Integration**: Dependencies are managed via vcpkg, which is integrated into the CMake build process using `CMAKE_TOOLCHAIN_FILE`. Ensure `VCPKG_ROOT` is set correctly in your environment if running builds outside of the CodeCrafters environment.
- **C23 Standard**: The project is configured to use the C23 standard. Be aware of language features specific to C23.
- **CodeCrafters specific files**: `your_program.sh` and `codecrafters.yml` are specific to the CodeCrafters platform for defining how the code is compiled and run in their environment. Local changes to `your_program.sh` won't affect remote execution.
