cmake_minimum_required(VERSION 3.21)
project(Sort_Algorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sort_Algorithm
        main.cpp
        algo/algos.hpp
        algo/helper.hpp
        algo/bubble_sort.cpp
        algo/selection_sort.cpp
        algo/insertion_sort.cpp
        algo/shell_sort.cpp
        algo/merge_sort.cpp
        algo/quick_sort.cpp
        algo/heap_sort.cpp
        algo/counting_sort.cpp
        algo/bucketSort.cpp
        algo/radix_sort.cpp
        )
# Catch2
find_package(Catch2 3 REQUIRED)

# spdlog
if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()


target_link_libraries(Sort_Algorithm PRIVATE
                      Catch2::Catch2WithMain
                      spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)