cmake_minimum_required(VERSION 3.10)

project(proj)

add_library(math SHARED math.c)
target_include_directories(math PRIVATE "./")
target_compile_definitions(math PRIVATE DLL_EXPORT)
