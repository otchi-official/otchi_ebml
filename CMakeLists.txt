cmake_minimum_required(VERSION 3.14)
project(otchi_ebml VERSION 0.0.1)

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE public_headers include/*.h)
file(GLOB_RECURSE private_files src/*.cpp src/*.h)

add_library(otchi_ebml ${public_headers} ${private_files})

target_include_directories(otchi_ebml 
		PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
		PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(tests)

# Install

install(TARGETS otchi_ebml
        EXPORT otchi_ebml
        ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# TODO: Better cmake directory?

install(FILES cmake/otchi_ebml-config.cmake DESTINATION cmake)

install(EXPORT otchi_ebml DESTINATION cmake)