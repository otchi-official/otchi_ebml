cmake_minimum_required(VERSION 3.14)
project(include/otchi_ebml)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++17)

set(headers
        include/otchi_ebml/types/ebml_clock.h
        include/otchi_ebml/elements/ebml_element.h
        include/otchi_ebml/elements/ebml_type.h
        include/otchi_ebml/types/ebml_path.h
        include/otchi_ebml/elements/ebml_element_int.h
        include/otchi_ebml/exceptions/not_initialized.h
        include/otchi_ebml/elements/ebml_element_factory.h
        include/otchi_ebml/tags/ebml/ebml_tags.h
        include/otchi_ebml/types/ebml_alias.h
        include/otchi_ebml/elements/ebml_element_uint.h
        include/otchi_ebml/elements/ebml_element_string.h
        include/otchi_ebml/elements/ebml_element_utf8.h
        include/otchi_ebml/elements/ebml_element_binary.h
        include/otchi_ebml/elements/ebml_element_double.h
        include/otchi_ebml/elements/ebml_element_date.h
        include/otchi_ebml/ebml_parser.h
        include/otchi_ebml/elements/ebml_document.h
        include/otchi_ebml/tags/matroska/matroska_tags.h)

file(GLOB tags "include/otchi_ebml/tags/*.h")
set(src main.cpp include/otchi_ebml/elements/ebml_element_master.h src/tags/ebml/ebml_tags.cpp src/tags/matroska/matroska_tags.cpp)


add_executable(otchi_ebml ${headers} ${src} ${tags})

target_include_directories(otchi_ebml PUBLIC include)
target_link_libraries(otchi_ebml stdc++fs)