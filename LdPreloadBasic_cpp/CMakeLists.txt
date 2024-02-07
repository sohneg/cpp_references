cmake_minimum_required(VERSION 3.12)
project(CrackMe CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add your source files
set(SOURCE_FILES main.cpp)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Optional: Set output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Optional: Set output directory for libraries
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Optional: Set output directory for archives
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
