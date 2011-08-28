# root build file for the KOCMOC-MAIN

cmake_minimum_required(VERSION 2.8)
project(kocmoc CXX)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# xcode Product Name
set(APP_NAME kocmoc)

# -- get it revision number (SHA1) -------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC KOCMOC_MAIN_GIT_SHA1)
message(STATUS "KOCMOC-MAIN revision hash is: ${KOCMOC_MAIN_GIT_SHA1}")


# -- doxygen -----------------------------------------------------------------
set(KOCMOC_CORE_DOXYGEN_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/docs)

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file(${PROJECT_SOURCE_DIR}/Doxyfile.in ${PROJECT_BINARY_DIR}/Doxyfile)
add_custom_target(doc-kocmoc-main
	${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile
	WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
	COMMENT "Generating API documentation with Doxygen" VERBATIM
	)
endif(DOXYGEN_FOUND)


# -- add subdirs -------------------------------------------------------------
add_subdirectory(external/kocmoc-core)
add_subdirectory(src)

# -- copy and configure ------------------------------------------------------
message(STATUS "configuring files...")
set(KOCMOC_MEDIA_PATH ${PROJECT_SOURCE_DIR}/media)
configure_file(media/kocmoc-config.xml.in ${EXECUTABLE_OUTPUT_PATH}/kocmoc-config.xml)