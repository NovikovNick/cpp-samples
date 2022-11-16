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

add_executable(reachable_nodes_with_restrictions "tst/reachable_nodes_with_restrictions.cc" src/leetcode/reachable_nodes_with_restrictions.cc)
target_include_directories(reachable_nodes_with_restrictions PRIVATE Boost::unit_test_framework)

add_executable(minimum_operations_to_halve_array_sum "tst/minimum_operations_to_halve_array_sum.cc" src/leetcode/minimum_operations_to_halve_array_sum.cc)
target_include_directories(minimum_operations_to_halve_array_sum PRIVATE Boost::unit_test_framework)

add_executable(fin_bottom_left_tree_value "tst/fin_bottom_left_tree_value.cc" src/leetcode/fin_bottom_left_tree_value.cc)
target_include_directories(fin_bottom_left_tree_value PRIVATE Boost::unit_test_framework)

add_executable(daily_temperatures "tst/daily_temperatures.cc" src/leetcode/daily_temperatures.cc)
target_include_directories(daily_temperatures PRIVATE Boost::unit_test_framework)

add_executable(minimum_absolute_sum_difference "tst/minimum_absolute_sum_difference.cc" src/leetcode/daily_temperatures.cc)
target_include_directories(minimum_absolute_sum_difference PRIVATE Boost::unit_test_framework)

add_executable(longest_consecutive_sequence "tst/longest_consecutive_sequence.cc" src/leetcode/longest_consecutive_sequence.cc)
target_include_directories(longest_consecutive_sequence PRIVATE Boost::unit_test_framework)

add_executable(longest_palindrome_by_concatenating_two_letter_words "tst/longest_palindrome_by_concatenating_two_letter_words.cc" src/leetcode/longest_palindrome_by_concatenating_two_letter_words.cc)
target_include_directories(longest_palindrome_by_concatenating_two_letter_words PRIVATE Boost::unit_test_framework)

add_executable(reverse_vowels_of_a_string "tst/reverse_vowels_of_a_string.cc" src/leetcode/reverse_vowels_of_a_string.cc)
target_include_directories(reverse_vowels_of_a_string PRIVATE Boost::unit_test_framework)

add_executable(word_search_ii "tst/word_search_ii.cc" src/leetcode/word_search_ii.cc)
target_include_directories(word_search_ii PRIVATE Boost::unit_test_framework)

add_executable(orderly_queue "tst/orderly_queue.cc" src/leetcode/orderly_queue.cc)
target_include_directories(orderly_queue PRIVATE Boost::unit_test_framework)

add_executable(maximum_69_number "tst/maximum_69_number.cc" src/leetcode/maximum_69_number.cc)
target_include_directories(maximum_69_number PRIVATE Boost::unit_test_framework)

add_executable(make_the_string_great "tst/make_the_string_great.cc" src/leetcode/make_the_string_great.cc)
target_include_directories(make_the_string_great PRIVATE Boost::unit_test_framework)

add_executable(online_stock_span "tst/online_stock_span.cc" src/leetcode/online_stock_span.cc)
target_include_directories(online_stock_span PRIVATE Boost::unit_test_framework)

add_executable(remove_all_adjacent_duplicates_in_string "tst/remove_all_adjacent_duplicates_in_string.cc" src/leetcode/remove_all_adjacent_duplicates_in_string.cc)
target_include_directories(remove_all_adjacent_duplicates_in_string PRIVATE Boost::unit_test_framework)

add_executable(minimum_genetic_mutation "tst/minimum_genetic_mutation.cc" src/leetcode/minimum_genetic_mutation.cc)
target_include_directories(minimum_genetic_mutation PRIVATE Boost::unit_test_framework)

add_executable(remove_duplicates_from_sorted_array "tst/remove_duplicates_from_sorted_array.cc" src/leetcode/remove_duplicates_from_sorted_array.cc)
target_include_directories(remove_duplicates_from_sorted_array PRIVATE Boost::unit_test_framework)

add_executable(where_will_the_ball_fall "tst/where_will_the_ball_fall.cc" src/leetcode/where_will_the_ball_fall.cc)
target_include_directories(where_will_the_ball_fall PRIVATE Boost::unit_test_framework)

add_executable(implement_trie_prefix_tree "tst/implement_trie_prefix_tree.cc" src/leetcode/implement_trie_prefix_tree.cc)
target_include_directories(implement_trie_prefix_tree PRIVATE Boost::unit_test_framework)

add_executable(reverse_words_in_a_string "tst/reverse_words_in_a_string.cc" src/leetcode/reverse_words_in_a_string.cc)
target_include_directories(reverse_words_in_a_string PRIVATE Boost::unit_test_framework)

add_executable(most_stones_removed_with_same_row_or_column "tst/most_stones_removed_with_same_row_or_column.cc" src/leetcode/most_stones_removed_with_same_row_or_column.cc)
target_include_directories(most_stones_removed_with_same_row_or_column PRIVATE Boost::unit_test_framework)

add_executable(count_complete_tree_nodes "tst/count_complete_tree_nodes.cc" src/leetcode/count_complete_tree_nodes.cc)
target_include_directories(count_complete_tree_nodes PRIVATE Boost::unit_test_framework)

add_executable(guess_number_higher_or_lower "tst/guess_number_higher_or_lower.cc" src/leetcode/guess_number_higher_or_lower.cc)
target_include_directories(guess_number_higher_or_lower PRIVATE Boost::unit_test_framework)

add_executable(aaa_empty "tst/aaa_empty.cc" src/leetcode/aaa_empty.cc)
target_include_directories(aaa_empty PRIVATE Boost::unit_test_framework)
