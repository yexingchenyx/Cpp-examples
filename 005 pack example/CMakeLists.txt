cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)

project(proj)

file(GLOB cpps "${PROJECT_SOURCE_DIR}/*.cpp")
add_executable(main ${cpps})


