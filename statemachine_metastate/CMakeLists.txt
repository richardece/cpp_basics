cmake_minimum_required (VERSION 3.8)

project(boostAndCMake)

set(BOOST_ROOT "/usr/local/boost_1_76_0") # either set it here or from the command line

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
#find_package(Boost REQUIRED COMPONENTS system) # header only libraries must not be added here

find_package(Boost 1.72 REQUIRED ) # header only libraries must not be added here

add_executable(main main.cpp ) 
target_include_directories(main PUBLIC ${Boost_INCLUDE_DIRS}) 
target_link_libraries(main ${Boost_LIBRARIES})