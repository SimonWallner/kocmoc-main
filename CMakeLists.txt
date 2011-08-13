# root build file for the KOCMOC-MAIN

cmake_minimum_required(VERSION 2.8)
project(kocmoc CXX)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(external/kocmoc-core)
add_subdirectory(src)