cmake_minimum_required(VERSION 3.14)
project(ftxui-grid-container)
include(cmake/ftxui.cmake)

add_library(ftxui-grid-container STATIC
    include/ftxui-grid-container/grid-container.hpp
    src/ftxui-grid-container/grid-container.cpp
    )
target_link_libraries(ftxui-grid-container PUBLIC ftxui::component)

target_include_directories(ftxui-grid-container PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    )
add_subdirectory(example)
