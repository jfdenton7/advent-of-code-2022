set(HEADER_LIST "${CMAKE_SOURCE_DIR}/include/advent/lib.hpp")

add_library(advent_of_code_lib lib.cpp ${HEADER_LIST})

target_compile_features(advent_of_code_lib PUBLIC cxx_std_17)

target_include_directories(advent_of_code_lib PUBLIC ../include)