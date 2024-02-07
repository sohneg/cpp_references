cmake_minimum_required(VERSION 3.12)

project(
  BasicCompilerDefinitionExample
  VERSION 1.0
  LANGUAGES CXX)

option(EXAMPLE_FLAG       "Description"       OFF)

include(cmake/compilerFlags.cmake)

add_subdirectory(src)

