# cmake list for src/

include_directories(
    ${PROJECT_SOURCE_DIR}/external/kocmoc-core/include
)

link_directories(
#    ${PROJECT_SOURCE_DIR}/external/kocmoc-core/lib
)

# collect the files
file(GLOB_RECURSE HEADER_FILES *.hpp)
file(GLOB_RECURSE SOURCE_FILES *.cpp)


add_executable(kocmoc MACOSX_BUNDLE ${SOURCE_FILES})

set (TARGET_LINK_LIBRARIES kocmoc
    kocmoc-core
)

target_link_libraries(${TARGET_LINK_LIBRARIES})





