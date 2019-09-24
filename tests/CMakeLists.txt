add_executable(test_ebml main.cpp)

target_include_directories(test_ebml PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test_ebml otchi_ebml)