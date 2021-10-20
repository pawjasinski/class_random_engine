cmake_minimum_required(VERSION 3.0)
set(LIB_NAME "RANDOM_GEN")
project(${LIB_NAME})

find_package(Threads REQUIRED)

aux_source_directory(. FILES)
set(BUILD_TYPE "SHARED")

set(CMAKE_BUILD_TYPE "Release")

add_library(${LIB_NAME} ${BUILD_TYPE} ${FILES})
message(STATUS "FILES: ${FILES}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o2 -Wall")
message(STATUS "FLAGS: ${CMAKE_CXX_FLAGS}")
target_link_libraries(${LIB_NAME} PRIVATE Threads::Threads)
target_compile_features(${LIB_NAME} PUBLIC cxx_std_14)