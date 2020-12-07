cmake_minimum_required(VERSION 3.10)
project(design_pattern)

set(CMAKE_CXX_STANDARD 14)

add_executable(builder_robot builder_robot.cpp builder_robot.h)
add_executable(factory_ufo factory_ufo.cpp factory_ufo.h)
add_executable(abstract_factory abstract_factory.cpp abstract_factory.h)
add_executable(concept_model_idiom concept_model_idiom.cpp concept_model_idiom.h)
add_executable(prototype prototype.cpp prototype.h)
add_executable(singleton_pattern singleton_pattern.cpp singleton_pattern.h)
add_executable(adapter adapter.cpp adapter.h)
add_executable(try try.cpp)