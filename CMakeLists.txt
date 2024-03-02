cmake_minimum_required(VERSION 3.1) # Set minimum CMake version
project(OneTBBExample) # Name your project

set(CMAKE_CXX_STANDARD 14) # Use C++14 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(TBB_TEST
    OFF
    CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS
    OFF
    CACHE BOOL "" FORCE)
FetchContent_Declare(
        oneTBB
        URL ${CMAKE_CURRENT_SOURCE_DIR}/oneTBB-2021.11.0.tar.gz
        URL_HASH
                SHA256=782ce0cab62df9ea125cdea253a50534862b563f1d85d4cda7ad4e77550ac363
)
FetchContent_MakeAvailable(oneTBB)
if(NOT TARGET TBB::tbb)
        message(ERROR "Failed to add oneTBB Library")
endif()

add_executable(one_tbb_example main.cpp) # Specify the executable and source file

target_link_libraries(one_tbb_example PRIVATE TBB::tbb) # Link oneTBB library
