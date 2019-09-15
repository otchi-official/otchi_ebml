cmake_minimum_required(VERSION 3.14)
project(include/otchi_ebml)

set(CMAKE_CXX_STANDARD 17)

set(headers
        include/otchi_ebml/ebml_value.h
        include/otchi_ebml/types/ebml_clock.h
        include/otchi_ebml/elements/ebml_element.h
        include/otchi_ebml/elements/ebml_type.h
        include/otchi_ebml/types/ebml_path.h
        include/otchi_ebml/elements/ebml_element_int.h
        include/otchi_ebml/exceptions/not_initialized.h
        include/otchi_ebml/elements/ebml_element_factory.h
        include/otchi_ebml/tags/ebml_tags.h
        include/otchi_ebml/types/ebml_alias.h
        include/otchi_ebml/elements/ebml_element_uint.h include/otchi_ebml/elements/ebml_element_string.h include/otchi_ebml/elements/ebml_element_utf8.h include/otchi_ebml/elements/ebml_element_binary.h include/otchi_ebml/elements/ebml_element_double.h include/otchi_ebml/elements/ebml_element_date.h include/otchi_ebml/ebml_parser.h include/otchi_ebml/elements/ebml_document.h include/otchi_ebml/tags/ebml_head.h include/otchi_ebml/tags/ebml_doc_type.h)
set(src main.cpp include/otchi_ebml/elements/ebml_element_master.h src/tags/ebml_tags.cpp)


add_executable(otchi_ebml ${headers} ${src})

target_include_directories(otchi_ebml PUBLIC include)