cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# global compile options 
add_compile_options(-g -Wall -Werror -Weffc++ -Wextra -Wconversion -Wsign-conversion -Wpedantic)

# project configuration
project(crpg
    VERSION 0.1
    DESCRIPTION "implementing dnd5e in c++"
    HOMEPAGE_URL "https://github.com/apszymanski/crpg"
    LANGUAGES CXX
)

# main project executable
add_executable(crpg src/main.cpp)

# configure file for project
configure_file(include/crpg_config.hpp.in config.hpp)

# add subprojects here
add_subdirectory(src/utility/)

# add include directories here
target_include_directories(crpg
    PUBLIC 
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/include/utility"
)

# link subprojects with main executable here
target_link_libraries(crpg dice)

# Testing 
enable_testing()
