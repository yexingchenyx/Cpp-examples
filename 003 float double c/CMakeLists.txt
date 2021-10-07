cmake_minimum_required(VERSION 3.15)

project(proj)

add_library(my STATIC max.c)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE my)
