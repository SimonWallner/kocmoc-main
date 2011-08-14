# root build file for the KOCMOC-MAIN

cmake_minimum_required(VERSION 2.8)
project(kocmoc CXX)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# xcode Product Name
set(APP_NAME kocmoc)

# get it revision number (SHA1)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC KOCMOC_MAIN_GIT_SHA1)

message(STATUS "KOCMOC-MAIN revision hash is: ${KOCMOC_MAIN_GIT_SHA1}")

add_subdirectory(external/kocmoc-core)
add_subdirectory(src)