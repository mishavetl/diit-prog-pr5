cmake_minimum_required(VERSION 3.12)
project(lr5)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SRCS
    "include/*.h"
    "src/lib/*.cpp"
)

file(GLOB_RECURSE TEST_SRCS
    "include/*.h"
    "tests/*.cpp"
)

include_directories(AFTER "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(lr5_lib ${SRCS})

add_executable(lr5 src/main.cpp)
add_executable(lr5_test ${TEST_SRCS})

target_link_libraries(lr5 lr5_lib)
target_link_libraries(lr5_test lr5_lib)