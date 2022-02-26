cmake_minimum_required(VERSION 3.10)
project(proj)

find_package(OpenMP REQUIRED)
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

add_executable(main main.cpp)
target_link_libraries(main PUBLIC OpenMP::OpenMP_CXX)