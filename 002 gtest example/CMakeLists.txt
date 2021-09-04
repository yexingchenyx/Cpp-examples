cmake_minimum_required(VERSION 3.14)

project(proj)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

enable_testing()

file(GLOB cpps "./*.cpp")
add_executable(
  main
  ${cpps}
)

target_link_libraries(
  main
  ${GTEST_BOTH_LIBRARIES} pthread
)

gtest_discover_tests(main)
