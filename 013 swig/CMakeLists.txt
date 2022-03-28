cmake_minimum_required(VERSION 3.10)

project(proj)
set (CMAKE_CXX_STANDARD 11)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/mylib/*.cpp)
add_library(mylib SHARED ${SRC_FILES})
target_include_directories(mylib PRIVATE "${PROJECT_SOURCE_DIR}/inc")
target_compile_definitions(mylib PRIVATE DLL_EXPORT)

cmake_policy(SET CMP0086 NEW)
cmake_policy(SET CMP0078 NEW)

find_package(SWIG REQUIRED)
find_package(Python3 COMPONENTS Development REQUIRED)
message(STATUS ${Python3_INCLUDE_DIRS})
message(STATUS ${Python3_LIBRARY_DIRS})
message(STATUS ${Python3_LIBRARIES})
INCLUDE(${SWIG_USE_FILE})
SET(CMAKE_SWIG_FLAGS "")
SET_SOURCE_FILES_PROPERTIES(mylibpy.i PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(mylibpy.i PROPERTIES SWIG_FLAGS "-includeall")
swig_add_library(mylibpy
                TYPE MODULE
                LANGUAGE python
                OUTPUT_DIR "./"
                OUTFILE_DIR "mylibpy_src"
                SOURCES mylibpy.i)
target_include_directories(${SWIG_MODULE_mylibpy_REAL_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/inc" ${Python3_INCLUDE_DIRS})
target_link_directories(${SWIG_MODULE_mylibpy_REAL_NAME} PRIVATE ${Python3_LIBRARY_DIRS})
target_link_libraries(${SWIG_MODULE_mylibpy_REAL_NAME} PRIVATE mylib ${Python3_LIBRARIES})
