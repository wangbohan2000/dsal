cmake_minimum_required(VERSION 3.13)
project(dsal)
message("\n Data structure and algorithm! \n")
set(CMAKE_CXX_STANDARD 11)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME} main.cpp include/leetcode.h)