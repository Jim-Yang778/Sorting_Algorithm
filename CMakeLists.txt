cmake_minimum_required(VERSION 3.21)
project(Sort_Algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sort_Algorithm main.cpp algo/bubble_sort.cpp algo/helper.hpp algo/algos.hpp)

find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(Sort_Algorithm PRIVATE Catch2::Catch2)