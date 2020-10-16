cmake_minimum_required(VERSION 3.10)
project(design_pattern)

set(CMAKE_CXX_STANDARD 11)

add_executable(builder_robot builder_robot.cpp builder_robot.h)
add_executable(factory_ufo factory_ufo.cpp factory_ufo.h)