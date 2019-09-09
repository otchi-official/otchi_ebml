cmake_minimum_required(VERSION 3.14)
project(include/otchi_ebml)

set(CMAKE_CXX_STANDARD 17)

set(headers include/otchi_ebml/ebml_value.h include/otchi_ebml/ebml_clock.h)
set(src main.cpp)


add_executable(otchi_ebml ${headers} ${src})

target_include_directories(otchi_ebml PUBLIC include)