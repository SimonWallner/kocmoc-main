# cmake list for src/

include_directories(
    ${PROJECT_SOURCE_DIR}/external/kocmoc-core/include
)

link_directories(
#    ${PROJECT_SOURCE_DIR}/external/kocmoc-core/lib
)

# collect the files
file(GLOB HEADER_FILES_MSVC *.hpp)
file(GLOB SOURCE_FILES *.cpp)



if (WIN32)
	# join the header files so that the VS can display them
	SET(SOURCE_FILES ${SOURCE_FILES} ${HEADER_FILES_MSVC})

	# MSVC resources stuff
#	file(GLOB RESOURCES_SHADERS_MSVC ../media/shaders/*)
#	source_group(foo FILES ../media/shaders/base.frag)
endif (WIN32)

add_executable(kocmoc ${SOURCE_FILES})

set (TARGET_LINK_LIBRARIES kocmoc
    kocmoc-core
)

target_link_libraries(${TARGET_LINK_LIBRARIES})





