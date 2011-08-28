# cmake list for src/

# -- find stuff --------------------------------------------------------------
find_package(Boost COMPONENTS program_options)
if(NOT Boost_FOUND)
	message(WARNING "Boost not found!")
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/external/kocmoc-core/include
	${Boost_INCLUDE_DIR}
)

link_directories(
	${Boost_LIBRARY_DIRS}
)

# collect the files
file(GLOB_RECURSE HEADER_FILES *.hpp)
file(GLOB_RECURSE SOURCE_FILES *.cpp)


add_executable(kocmoc ${SOURCE_FILES})

set (TARGET_LINK_LIBRARIES kocmoc
    kocmoc-core
	${Boost_PROGRAM_OPTIONS_LIBRARY}
)

target_link_libraries(${TARGET_LINK_LIBRARIES})





