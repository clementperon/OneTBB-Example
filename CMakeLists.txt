cmake_minimum_required(VERSION 3.1) # Set minimum CMake version
project(OneTBBExample) # Name your project

set(CMAKE_CXX_STANDARD 11) # Use C++11 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(TBB REQUIRED) # Find oneTBB library

add_executable(one_tbb_example main.cpp) # Specify the executable and source file

target_link_libraries(one_tbb_example PRIVATE TBB::tbb) # Link oneTBB library
