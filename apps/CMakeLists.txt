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
# day 3
add_executable(day_3 day_3.cpp)
target_compile_features(day_3 PRIVATE cxx_std_17)
target_include_directories(day_3 PUBLIC ./)
target_link_libraries(day_3 PRIVATE advent_of_code_lib)
# day 4
add_executable(day_4 day_4.cpp)
target_compile_features(day_4 PRIVATE cxx_std_17)
target_include_directories(day_4 PUBLIC ./)
target_link_libraries(day_4 PRIVATE advent_of_code_lib)
# day 5
add_executable(day_5 day_5.cpp)
target_compile_features(day_5 PRIVATE cxx_std_17)
target_include_directories(day_5 PUBLIC ./)
target_link_libraries(day_5 PRIVATE advent_of_code_lib)
# day 6
add_executable(day_6 day_6.cpp)
target_compile_features(day_6 PRIVATE cxx_std_17)
target_include_directories(day_6 PUBLIC ./)
target_link_libraries(day_6 PRIVATE advent_of_code_lib)
# day 7
add_executable(day_7 day_7.cpp)
target_compile_features(day_7 PRIVATE cxx_std_17)
target_include_directories(day_7 PUBLIC ./)
target_link_libraries(day_7 PRIVATE advent_of_code_lib)
# day 8
add_executable(day_8 day_8.cpp)
target_compile_features(day_8 PRIVATE cxx_std_17)
target_include_directories(day_8 PUBLIC ./)
target_link_libraries(day_8 PRIVATE advent_of_code_lib)
# test
add_executable(test "test.cpp")
target_compile_features(test PRIVATE cxx_std_17)
target_link_libraries(test PRIVATE advent_of_code_lib)
