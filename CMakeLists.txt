cmake_minimum_required(VERSION 3.14)
project(include/otchi_ebml)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)

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


add_library(otchi_ebml ${headers} ${src} ${tags})

target_include_directories(otchi_ebml PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

set_target_properties(otchi_ebml PROPERTIES PUBLIC_HEADER "${headers}")

# Install

install(TARGETS otchi_ebml
        EXPORT otchi_ebml-targets
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/otchi_ebml
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )

install(EXPORT otchi_ebml-targets
        NAMESPACE otchi::
        FILE otchi_ebml-targets.cmake
        DESTINATION lib/cmake/otchi_ebml
        )

export(EXPORT otchi_ebml-targets
        NAMESPACE otchi::
        FILE "${CMAKE_CURRENT_BINARY_DIR}/otchi_ebml-targets.cmake"
        )