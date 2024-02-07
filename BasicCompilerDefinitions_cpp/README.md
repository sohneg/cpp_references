# Basic Compiler Definitions C++

This repository serves as an example showcasing the usage of a compiler definition flag, specifically the `EXAMPLE_FLAG`. Compiler definition flags are powerful tools in C++ development that enable conditional compilation, allowing you to dynamically alter your code based on compile-time configurations.

## What is a compiler definition?

Compiler definitions, often set through flags, provide a mechanism for including or excluding specific portions of code during the compilation process. This flexibility is invaluable for managing different build configurations and scenarios.

## Example in this Repository

In this repository, the `EXAMPLE_FLAG` is employed to dynamically set a timeout variable in the code. The main file, `main.cpp`, uses the flag to conditionally define the `TIMEOUT_DURATION` based on whether `EXAMPLE_FLAG` is set.

---

### CMake Configuration

The CMake configuration file (`CMakeLists.txt`) initializes the project and introduces the `EXAMPLE_FLAG` as an option. The default value is `OFF`

```cmake
option(EXAMPLE_FLAG       "Description"       OFF)
```

The configuration is further handled by the `cmake/compilerFlags.cmake` file.

```cmake
if(EXAMPLE_FLAG)
    add_compile_definitions(EXAMPLE_FLAG)
endif()
```

In this snippet, if `EXAMPLE_FLAG` is set, it is added as a compile definition during compilation.

---

### Main Code (main.cpp)

```cpp
#include <iostream>

#ifdef EXAMPLE_FLAG
    #define TIMEOUT_DURATION 5  // Set a short timeout for the example
#else
    #define TIMEOUT_DURATION (1000 * 60)  // Default timeout for regular usage
#endif

int32_t timeout{TIMEOUT_DURATION};

int main(){
  std::cout << "Timeout: " << timeout << std::endl;
  return 0;
}
```

In this example, if `EXAMPLE_FLAG` is set during compilation, the `TIMEOUT_DURATION` is defined as 5 seconds; otherwise, it defaults to a longer duration of one minute.

This repository serves as a simple yet illustrative example of how compiler definition flags can be leveraged to adapt code behavior according to specific requirements or scenarios. Understanding and using such flags can greatly enhance the flexibility and versatility of your C++ projects.


# How to Use This Repository

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/sohneg/Basic_Compiler_Definitions_cpp
   cd Basic_Compiler_Definitions_cpp
   ```

2. **Create a Build Directory:**
   ```bash
   mkdir build
   cd build
   ```

3. **Run CMake with or without EXAMPLE_FLAG:**
   - **With EXAMPLE_FLAG ON:**
     ```bash
     cmake -DEXAMPLE_FLAG=ON ..
     ```
   - **With EXAMPLE_FLAG OFF:**
     ```bash
     cmake -DEXAMPLE_FLAG=OFF ..
     ```

4. **Build the Project:**
   ```bash
   make
   ```

5. **Run the Executable:**
   ```bash
   ./src/MAIN
   ```

   This will execute the compiled code, and the output will reflect the timeout value based on whether `EXAMPLE_FLAG` is set.


### Additional Notes:

- The `mkdir build` and `cd build` steps are standard practice for out-of-source builds, keeping your source directory clean.
  
- Adjust the `cmake -DEXAMPLE_FLAG=ON/OFF ..` command based on whether you want to enable or disable the `EXAMPLE_FLAG` during compilation.

- Ensure that you have the necessary build tools and dependencies installed before running CMake.

---