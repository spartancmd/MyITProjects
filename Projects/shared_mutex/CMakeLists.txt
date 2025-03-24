cmake_minimum_required(VERSION 3.27 FATAL_ERROR)
project(test LANGUAGES CXX)

add_subdirectory(lib)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
add_executable(test main.cpp)

target_link_libraries(test shared_mutex)
