cmake_minimum_required(VERSION 3.0)

project(cpp_daemons_sample)

add_subdirectory(lib)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/cmake" ${CMAKE_MODULE_PATH})

if (NOT EXTRA_COMPILE_FLAGS)
	set (EXTRA_COMPILE_FLAGS "-Wall -Wunused -march=nocona --std=c++14")
	set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${EXTRA_COMPILE_FLAGS}")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_COMPILE_FLAGS}")
endif()

if (NOT EXTRA_LINKER_FLAGS)
	set (EXTRA_LINKER_FLAGS "-Wl, --as-needed --no-undefined")
	set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
	set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${EXTRA_LINKER_FLAGS}")
endif()
include_directories(
	lib/include
)

add_subdirectory(daemon_sample)
