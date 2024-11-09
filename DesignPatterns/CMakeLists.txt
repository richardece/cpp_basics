cmake_minimum_required(VERSION 3.15)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 17)
get_directory_property(MYDEFS COMPILE_DEFINITIONS)
MESSAGE( STATUS "Compile defs contain: " ${MYDEFS} )

add_executable(DesignPatterns main.cpp)
add_executable(Factory Factory.cpp)