cmake_minimum_required(VERSION 3.0)

project(daemon_skeleton)

set(target_src
		daemon_skeleton.cc
		sample.cc)

set_property(SOURCE ${target_src} main.cc
		PROPERTY
		COMPILE_FLAGS "-g -O2 -Wall -Wunused --std=c++14")

add_executable(daemon ${target_src}
		main.cc)

target_link_libraries(daemon ${link_libs})
add_custom_command(TARGET daemon
		POST_BUILD
		COMMAND strip ./daemon)
