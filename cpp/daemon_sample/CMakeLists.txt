cmake_minimum_required(VERSION 3.0)

project(daemon_sample)

include(GNUInstallDirs)
include_directories(include)

file(GLOB daemon_sample_SOURCES
	src/*.cc)

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

add_library(daemon-lib STATIC ${daemon_sample_SOURCES})
set_target_properties(daemon-lib PROPERTIES OUTPUT_NAME daemons)
target_link_libraries(daemon-lib libdaemons)

set(LIBRARIES
	daemon-lib
)

add_executable(daemon_sample ${daemon_sample_SOURCES})
target_link_libraries(daemon_sample ${LIBRARIES})
