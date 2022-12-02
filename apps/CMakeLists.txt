add_executable(day_1 day_1.cpp)
target_compile_features(day_1 PRIVATE cxx_std_17)

target_link_libraries(day_1 PRIVATE advent_of_code_lib)