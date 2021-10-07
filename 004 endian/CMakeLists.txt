cmake_minimum_required(VERSION 3.15)

project(proj)

find_package(Boost REQUIRED)

file(GLOB cpps "${PROJECT_SOURCE_DIR}/*.cpp")
add_executable(main ${cpps})
target_include_directories(main PRIVATE ${Boost_INCLUDE_DIRS})
