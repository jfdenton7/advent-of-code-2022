# day 1
add_executable(day_1 day_1.cpp)
target_compile_features(day_1 PRIVATE cxx_std_17)
target_include_directories(day_1 PUBLIC ./)
target_link_libraries(day_1 PRIVATE advent_of_code_lib)
# day 2
add_executable(day_2 day_2.cpp)
target_compile_features(day_2 PRIVATE cxx_std_17)
target_include_directories(day_2 PUBLIC ./)
target_link_libraries(day_2 PRIVATE advent_of_code_lib)