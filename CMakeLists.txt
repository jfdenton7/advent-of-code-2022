cmake_minimum_required(VERSION 3.10)

project(AdventOfCode VERSION 0.1
                     DESCRIPTION "advent of code 2022"
                     LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# add_library(AdventOfCodeLib lib.cpp lib.hpp)

# add_executable(day_1 day_1.cpp)
add_subdirectory(src)
add_subdirectory(apps)

# target_link_libraries(day_1 PRIVATE AdventOfCodeLib)
