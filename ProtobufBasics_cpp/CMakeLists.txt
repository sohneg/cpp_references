# Set the minimum required version of CMake. 
# This ensures that the CMake version used is at least 3.8.
cmake_minimum_required(VERSION 3.8)

# Declare the project with the given name "protobuf_example" and specify the language as C++.
project(protobuf_example CXX)

add_subdirectory(proto)
# Create an executable named "my_app" using the specified source files.
add_executable(my_app src/main.cpp)

# Define private compile definitions for the target "my_app".
# In this case, set the C++ standard to C++11.
target_compile_definitions(my_app PRIVATE cxx_std_20)

# Link the "my_app" target with my protobuf lib.
# this imports the dependencies
target_link_libraries(my_app PRIVATE myproto)
