# Basic LD_PRELOAD Example

This is a basic example demonstrating the use of `LD_PRELOAD` in a C++ program.

## What is LD_PRELOAD?

`LD_PRELOAD` is an environment variable used in Unix-like operating systems to load a specified shared library before all others during the dynamic linking process. This allows users to override or intercept specific functions in other dynamically linked libraries.

## How to Use LD_PRELOAD

The `LD_PRELOAD` mechanism is often employed for various purposes, such as debugging, profiling, or altering the behavior of existing applications without modifying their source code. In this example, we use `LD_PRELOAD` to intercept and override the standard C library's `strcmp` function.

## How to Build

1. Clone the repository:
   ```bash
   git clone https://github.com/sohneg/LD_PRELOAD_basic_cpp
   cd LD_PRELOAD_basic_cpp
   ```

2. Build the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Build preload.cpp:
    ```bash
    gcc -shared -fPIC ../preload.cpp -o libpreload.so
    ```

## How to Run

### Run Normal:
```bash
./CrackMe
```

### Run with LD_PRELOAD:
```bash
LD_PRELOAD=$PWD/libpreload.so ./CrackMe
```