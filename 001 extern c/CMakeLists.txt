cmake_minimum_required(VERSION 3.10)

set(CMAKE_VERBOSE_MAKEFILE on)

project(proj)

add_library(cmodule STATIC c_module.c)

add_library(cppmodule STATIC cpp_module.cpp)

add_executable(cmain c_main.c)
target_link_libraries(cmain PRIVATE cmodule cppmodule)
set_target_properties(cmain PROPERTIES LINKER_LANGUAGE C)

add_executable(cppmain cpp_main.cpp)
target_link_libraries(cppmain PRIVATE cmodule cppmodule)
set_target_properties(cppmain PROPERTIES LINKER_LANGUAGE CXX)