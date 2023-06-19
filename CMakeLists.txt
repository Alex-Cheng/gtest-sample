cmake_minimum_required(VERSION 3.0)

project(GTestSample LANGUAGES CXX)

set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

configure_file(
    "${PROJECT_SOURCE_DIR}/config/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

include_directories("${PROJECT_BINARY_DIR}")

macro(add_glob cur_list)
    file(GLOB __tmp CONFIGURE_DEPENDS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${ARGN})
    list(APPEND ${cur_list} ${__tmp})
endmacro()

macro(add_headers_and_sources prefix common_path)
    add_glob(${prefix}_headers ${CMAKE_CURRENT_SOURCE_DIR} ${common_path}/*.h)
    add_glob(${prefix}_sources ${common_path}/*.cpp ${common_path}/*.c ${common_path}/*.h)
endmacro()

add_subdirectory(src)
add_subdirectory(tests)
