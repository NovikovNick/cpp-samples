cmake_minimum_required (VERSION 3.8)
project (CppSamples)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(BOOST_ROOT "C:\\local\\boost_1_80_0")
set(Boost_DEBUG ON)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
add_definitions( -DBOOST_ALL_NO_LIB )
add_definitions( -DBOOST_ALL_DYN_LINK )

add_subdirectory("src")

include_directories(${Boost_INCLUDE_DIRS})

file(GLOB CPP_SAMPLES_UTIL  "src/util/*.h" "src/util/*.cc")
    
add_executable(CppSamples src/main.cpp)
target_link_libraries(CppSamples)

add_executable(redistribute_characters_to_make_all_strings_equal "tst/redistribute_characters_to_make_all_strings_equal.cc" src/leetcode/redistribute_characters_to_make_all_strings_equal.cc)
target_include_directories(redistribute_characters_to_make_all_strings_equal PRIVATE Boost::unit_test_framework)

add_executable(find-median-from-data-stream "tst/find-median-from-data-stream.cc" src/leetcode/find-median-from-data-stream.cc)
target_include_directories(find-median-from-data-stream PRIVATE Boost::unit_test_framework)

add_executable(two_sum "tst/two_sum.cc" src/leetcode/two_sum.cc)
target_include_directories(two_sum PRIVATE Boost::unit_test_framework)

add_executable(length-of-the-longest-alphabetical-continuous-substring "tst/length-of-the-longest-alphabetical-continuous-substring.cc" src/leetcode/length-of-the-longest-alphabetical-continuous-substring.cc)
target_include_directories(length-of-the-longest-alphabetical-continuous-substring PRIVATE Boost::unit_test_framework)

add_executable(letter-case-permutation "tst/letter-case-permutation.cc" src/leetcode/letter-case-permutation.cc)
target_include_directories(letter-case-permutation PRIVATE Boost::unit_test_framework)

add_executable(recover-a-tree-from-preorder-traversal  "tst/recover-a-tree-from-preorder-traversal.cc" src/leetcode/recover-a-tree-from-preorder-traversal.cc ${CPP_SAMPLES_UTIL} )
target_include_directories(recover-a-tree-from-preorder-traversal PRIVATE Boost::unit_test_framework)

add_executable(minimum_number_of_work_sessions_to_finish_the_tasks "tst/minimum_number_of_work_sessions_to_finish_the_tasks.cc" src/leetcode/minimum_number_of_work_sessions_to_finish_the_tasks.cc)
target_include_directories(minimum_number_of_work_sessions_to_finish_the_tasks PRIVATE Boost::unit_test_framework)

add_executable(advantage_shuffle "tst/advantage_shuffle.cc" src/leetcode/advantage_shuffle.cc)
target_include_directories(advantage_shuffle PRIVATE Boost::unit_test_framework)

add_executable(largest-rectangle-in-histogram "tst/largest-rectangle-in-histogram.cc" src/leetcode/largest-rectangle-in-histogram.cc)
target_include_directories(largest-rectangle-in-histogram PRIVATE Boost::unit_test_framework)

add_executable(integer_to_roman "tst/integer_to_roman.cc" src/leetcode/integer_to_roman.cc)
target_include_directories(integer_to_roman PRIVATE Boost::unit_test_framework)

add_executable(can_make_palindrome_from_substring "tst/can_make_palindrome_from_substring.cc" src/leetcode/can_make_palindrome_from_substring.cc)
target_include_directories(can_make_palindrome_from_substring PRIVATE Boost::unit_test_framework)

add_executable(minimum_time_visiting_all_points "tst/minimum_time_visiting_all_points.cc" src/leetcode/minimum_time_visiting_all_points.cc)
target_include_directories(minimum_time_visiting_all_points PRIVATE Boost::unit_test_framework)

add_executable(count_servers_that_communicate "tst/count_servers_that_communicate.cc" src/leetcode/count_servers_that_communicate.cc)
target_include_directories(count_servers_that_communicate PRIVATE Boost::unit_test_framework)

add_executable(maximum_product_of_three_numbers "tst/maximum_product_of_three_numbers.cc" src/leetcode/maximum_product_of_three_numbers.cc)
target_include_directories(maximum_product_of_three_numbers PRIVATE Boost::unit_test_framework)

add_executable(determine_if_string_halves_are_alike "tst/determine_if_string_halves_are_alike.cc" src/leetcode/determine_if_string_halves_are_alike.cc)
target_include_directories(determine_if_string_halves_are_alike PRIVATE Boost::unit_test_framework)

add_executable(minimum_initial_energy_to_finish_tasks "tst/minimum_initial_energy_to_finish_tasks.cc" src/leetcode/minimum_initial_energy_to_finish_tasks.cc)
target_include_directories(minimum_initial_energy_to_finish_tasks PRIVATE Boost::unit_test_framework)

add_executable(binary_tree_paths "tst/binary_tree_paths.cc" src/leetcode/binary_tree_paths.cc)
target_include_directories(binary_tree_paths PRIVATE Boost::unit_test_framework)

add_executable(stickers_to_spell_word "tst/stickers_to_spell_word.cc" src/leetcode/stickers_to_spell_word.cc)
target_include_directories(stickers_to_spell_word PRIVATE Boost::unit_test_framework)
