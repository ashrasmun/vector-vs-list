cmake_minimum_required(VERSION 3.14)

project(vector_vs_list)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_executable(
  vector_vs_list
  src/main.cpp
  )
