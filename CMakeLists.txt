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

file(GLOB CPP_SAMPLES_UTIL "src/util/*.h" "src/util/*.cc")
file(GLOB SOCKET "src/socket/**/*.h" "src/socket/**/*.cc")
file(GLOB CONCURRENCY "src/concurrency/**/*.h" "src/concurrency/**/*.cc")


add_executable(main src/main.cpp ${SOCKET} ${CONCURRENCY})
if(WIN32)
  target_link_libraries(main wsock32 ws2_32)
endif()

#add_executable(redistribute_characters_to_make_all_strings_equal "tst/redistribute_characters_to_make_all_strings_equal.cc" src/leetcode/redistribute_characters_to_make_all_strings_equal.cc)
#target_include_directories(redistribute_characters_to_make_all_strings_equal PRIVATE Boost::unit_test_framework)

#add_executable(find-median-from-data-stream "tst/find-median-from-data-stream.cc" src/leetcode/find-median-from-data-stream.cc)
#target_include_directories(find-median-from-data-stream PRIVATE Boost::unit_test_framework)

#add_executable(two_sum "tst/two_sum.cc" src/leetcode/two_sum.cc)
#target_include_directories(two_sum PRIVATE Boost::unit_test_framework)

#add_executable(length-of-the-longest-alphabetical-continuous-substring "tst/length-of-the-longest-alphabetical-continuous-substring.cc" src/leetcode/length-of-the-longest-alphabetical-continuous-substring.cc)
#target_include_directories(length-of-the-longest-alphabetical-continuous-substring PRIVATE Boost::unit_test_framework)

#add_executable(letter-case-permutation "tst/letter-case-permutation.cc" src/leetcode/letter-case-permutation.cc)
#target_include_directories(letter-case-permutation PRIVATE Boost::unit_test_framework)

#add_executable(recover-a-tree-from-preorder-traversal  "tst/recover-a-tree-from-preorder-traversal.cc" src/leetcode/recover-a-tree-from-preorder-traversal.cc ${CPP_SAMPLES_UTIL} )
#target_include_directories(recover-a-tree-from-preorder-traversal PRIVATE Boost::unit_test_framework)

#add_executable(minimum_number_of_work_sessions_to_finish_the_tasks "tst/minimum_number_of_work_sessions_to_finish_the_tasks.cc" src/leetcode/minimum_number_of_work_sessions_to_finish_the_tasks.cc)
#target_include_directories(minimum_number_of_work_sessions_to_finish_the_tasks PRIVATE Boost::unit_test_framework)

#add_executable(advantage_shuffle "tst/advantage_shuffle.cc" src/leetcode/advantage_shuffle.cc)
#target_include_directories(advantage_shuffle PRIVATE Boost::unit_test_framework)

#add_executable(largest-rectangle-in-histogram "tst/largest-rectangle-in-histogram.cc" src/leetcode/largest-rectangle-in-histogram.cc)
#target_include_directories(largest-rectangle-in-histogram PRIVATE Boost::unit_test_framework)

#add_executable(integer_to_roman "tst/integer_to_roman.cc" src/leetcode/integer_to_roman.cc)
#target_include_directories(integer_to_roman PRIVATE Boost::unit_test_framework)

#add_executable(can_make_palindrome_from_substring "tst/can_make_palindrome_from_substring.cc" src/leetcode/can_make_palindrome_from_substring.cc)
#target_include_directories(can_make_palindrome_from_substring PRIVATE Boost::unit_test_framework)

#add_executable(minimum_time_visiting_all_points "tst/minimum_time_visiting_all_points.cc" src/leetcode/minimum_time_visiting_all_points.cc)
#target_include_directories(minimum_time_visiting_all_points PRIVATE Boost::unit_test_framework)

#add_executable(count_servers_that_communicate "tst/count_servers_that_communicate.cc" src/leetcode/count_servers_that_communicate.cc)
#target_include_directories(count_servers_that_communicate PRIVATE Boost::unit_test_framework)

#add_executable(maximum_product_of_three_numbers "tst/maximum_product_of_three_numbers.cc" src/leetcode/maximum_product_of_three_numbers.cc)
#target_include_directories(maximum_product_of_three_numbers PRIVATE Boost::unit_test_framework)

#add_executable(determine_if_string_halves_are_alike "tst/determine_if_string_halves_are_alike.cc" src/leetcode/determine_if_string_halves_are_alike.cc)
#target_include_directories(determine_if_string_halves_are_alike PRIVATE Boost::unit_test_framework)

#add_executable(minimum_initial_energy_to_finish_tasks "tst/minimum_initial_energy_to_finish_tasks.cc" src/leetcode/minimum_initial_energy_to_finish_tasks.cc)
#target_include_directories(minimum_initial_energy_to_finish_tasks PRIVATE Boost::unit_test_framework)

#add_executable(binary_tree_paths "tst/binary_tree_paths.cc" src/leetcode/binary_tree_paths.cc)
#target_include_directories(binary_tree_paths PRIVATE Boost::unit_test_framework)

#add_executable(stickers_to_spell_word "tst/stickers_to_spell_word.cc" src/leetcode/stickers_to_spell_word.cc)
#target_include_directories(stickers_to_spell_word PRIVATE Boost::unit_test_framework)

#add_executable(reachable_nodes_with_restrictions "tst/reachable_nodes_with_restrictions.cc" src/leetcode/reachable_nodes_with_restrictions.cc)
#target_include_directories(reachable_nodes_with_restrictions PRIVATE Boost::unit_test_framework)

#add_executable(minimum_operations_to_halve_array_sum "tst/minimum_operations_to_halve_array_sum.cc" src/leetcode/minimum_operations_to_halve_array_sum.cc)
#target_include_directories(minimum_operations_to_halve_array_sum PRIVATE Boost::unit_test_framework)

#add_executable(fin_bottom_left_tree_value "tst/fin_bottom_left_tree_value.cc" src/leetcode/fin_bottom_left_tree_value.cc)
#target_include_directories(fin_bottom_left_tree_value PRIVATE Boost::unit_test_framework)

#add_executable(daily_temperatures "tst/daily_temperatures.cc" src/leetcode/daily_temperatures.cc)
#target_include_directories(daily_temperatures PRIVATE Boost::unit_test_framework)

#add_executable(minimum_absolute_sum_difference "tst/minimum_absolute_sum_difference.cc" src/leetcode/daily_temperatures.cc)
#target_include_directories(minimum_absolute_sum_difference PRIVATE Boost::unit_test_framework)

#add_executable(longest_consecutive_sequence "tst/longest_consecutive_sequence.cc" src/leetcode/longest_consecutive_sequence.cc)
#target_include_directories(longest_consecutive_sequence PRIVATE Boost::unit_test_framework)

#add_executable(longest_palindrome_by_concatenating_two_letter_words "tst/longest_palindrome_by_concatenating_two_letter_words.cc" src/leetcode/longest_palindrome_by_concatenating_two_letter_words.cc)
#target_include_directories(longest_palindrome_by_concatenating_two_letter_words PRIVATE Boost::unit_test_framework)

#add_executable(reverse_vowels_of_a_string "tst/reverse_vowels_of_a_string.cc" src/leetcode/reverse_vowels_of_a_string.cc)
#target_include_directories(reverse_vowels_of_a_string PRIVATE Boost::unit_test_framework)

#add_executable(word_search_ii "tst/word_search_ii.cc" src/leetcode/word_search_ii.cc)
#target_include_directories(word_search_ii PRIVATE Boost::unit_test_framework)

#add_executable(orderly_queue "tst/orderly_queue.cc" src/leetcode/orderly_queue.cc)
#target_include_directories(orderly_queue PRIVATE Boost::unit_test_framework)

#add_executable(maximum_69_number "tst/maximum_69_number.cc" src/leetcode/maximum_69_number.cc)
#target_include_directories(maximum_69_number PRIVATE Boost::unit_test_framework)

#add_executable(make_the_string_great "tst/make_the_string_great.cc" src/leetcode/make_the_string_great.cc)
#target_include_directories(make_the_string_great PRIVATE Boost::unit_test_framework)

#add_executable(online_stock_span "tst/online_stock_span.cc" src/leetcode/online_stock_span.cc)
#target_include_directories(online_stock_span PRIVATE Boost::unit_test_framework)

#add_executable(remove_all_adjacent_duplicates_in_string "tst/remove_all_adjacent_duplicates_in_string.cc" src/leetcode/remove_all_adjacent_duplicates_in_string.cc)
#target_include_directories(remove_all_adjacent_duplicates_in_string PRIVATE Boost::unit_test_framework)

#add_executable(minimum_genetic_mutation "tst/minimum_genetic_mutation.cc" src/leetcode/minimum_genetic_mutation.cc)
#target_include_directories(minimum_genetic_mutation PRIVATE Boost::unit_test_framework)

#add_executable(remove_duplicates_from_sorted_array "tst/remove_duplicates_from_sorted_array.cc" src/leetcode/remove_duplicates_from_sorted_array.cc)
#target_include_directories(remove_duplicates_from_sorted_array PRIVATE Boost::unit_test_framework)

#add_executable(where_will_the_ball_fall "tst/where_will_the_ball_fall.cc" src/leetcode/where_will_the_ball_fall.cc)
#target_include_directories(where_will_the_ball_fall PRIVATE Boost::unit_test_framework)

#add_executable(implement_trie_prefix_tree "tst/implement_trie_prefix_tree.cc" src/leetcode/implement_trie_prefix_tree.cc)
#target_include_directories(implement_trie_prefix_tree PRIVATE Boost::unit_test_framework)

#add_executable(reverse_words_in_a_string "tst/reverse_words_in_a_string.cc" src/leetcode/reverse_words_in_a_string.cc)
#target_include_directories(reverse_words_in_a_string PRIVATE Boost::unit_test_framework)

#add_executable(most_stones_removed_with_same_row_or_column "tst/most_stones_removed_with_same_row_or_column.cc" src/leetcode/most_stones_removed_with_same_row_or_column.cc)
#target_include_directories(most_stones_removed_with_same_row_or_column PRIVATE Boost::unit_test_framework)

#add_executable(count_complete_tree_nodes "tst/count_complete_tree_nodes.cc" src/leetcode/count_complete_tree_nodes.cc)
#target_include_directories(count_complete_tree_nodes PRIVATE Boost::unit_test_framework)

#add_executable(guess_number_higher_or_lower "tst/guess_number_higher_or_lower.cc" src/leetcode/guess_number_higher_or_lower.cc)
#target_include_directories(guess_number_higher_or_lower PRIVATE Boost::unit_test_framework)

#add_executable(rectangle_area "tst/rectangle_area.cc" src/leetcode/rectangle_area.cc)
#target_include_directories(rectangle_area PRIVATE Boost::unit_test_framework)

#add_executable(ugly_number "tst/ugly_number.cc" src/leetcode/ugly_number.cc)
#target_include_directories(ugly_number PRIVATE Boost::unit_test_framework)

#add_executable(erect_the_fence "tst/erect_the_fence.cc" src/leetcode/erect_the_fence.cc)
#target_include_directories(erect_the_fence PRIVATE Boost::unit_test_framework)

#add_executable(basic_calculator "tst/basic_calculator.cc" src/leetcode/basic_calculator.cc)
#target_include_directories(basic_calculator PRIVATE Boost::unit_test_framework)

#add_executable(nearest_exit_from_entrance_in_maze "tst/nearest_exit_from_entrance_in_maze.cc" src/leetcode/nearest_exit_from_entrance_in_maze.cc)
#target_include_directories(nearest_exit_from_entrance_in_maze PRIVATE Boost::unit_test_framework)

#add_executable(perfect_squares "tst/perfect_squares.cc" src/leetcode/perfect_squares.cc)
#target_include_directories(perfect_squares PRIVATE Boost::unit_test_framework)

#add_executable(valid_sudoku "tst/valid_sudoku.cc" src/leetcode/valid_sudoku.cc)
#target_include_directories(valid_sudoku PRIVATE Boost::unit_test_framework)

#add_executable(word_search "tst/word_search.cc" src/leetcode/word_search.cc)
#target_include_directories(word_search PRIVATE Boost::unit_test_framework)

#add_executable(sum_of_subarray_minimums "tst/sum_of_subarray_minimums.cc" src/leetcode/sum_of_subarray_minimums.cc)
#target_include_directories(sum_of_subarray_minimums PRIVATE Boost::unit_test_framework)

#add_executable(maximum_profit_in_job_scheduling "tst/maximum_profit_in_job_scheduling.cc" src/leetcode/maximum_profit_in_job_scheduling.cc)
#target_include_directories(maximum_profit_in_job_scheduling PRIVATE Boost::unit_test_framework)

#add_executable(find_players_with_zero_or_one_losses "tst/find_players_with_zero_or_one_losses.cc" src/leetcode/find_players_with_zero_or_one_losses.cc)
#target_include_directories(find_players_with_zero_or_one_losses PRIVATE Boost::unit_test_framework)

#add_executable(insert_delete_getrandom_o1 "tst/insert_delete_getrandom_o1.cc" src/leetcode/insert_delete_getrandom_o1.cc)
#target_include_directories(insert_delete_getrandom_o1 PRIVATE Boost::unit_test_framework)

#add_executable(unique_number_of_occurrences "tst/unique_number_of_occurrences.cc" src/leetcode/unique_number_of_occurrences.cc)
#target_include_directories(unique_number_of_occurrences PRIVATE Boost::unit_test_framework)

#add_executable(determine_if_two_strings_are_close "tst/determine_if_two_strings_are_close.cc" src/leetcode/determine_if_two_strings_are_close.cc)
#target_include_directories(determine_if_two_strings_are_close PRIVATE Boost::unit_test_framework)

#add_executable(sort_characters_by_frequency "tst/sort_characters_by_frequency.cc" src/leetcode/sort_characters_by_frequency.cc)
#target_include_directories(sort_characters_by_frequency PRIVATE Boost::unit_test_framework)

#add_executable(minimum_average_difference "tst/minimum_average_difference.cc" src/leetcode/minimum_average_difference.cc)
#target_include_directories(minimum_average_difference PRIVATE Boost::unit_test_framework)

#add_executable(middle_of_the_linked_list "tst/middle_of_the_linked_list.cc" src/leetcode/middle_of_the_linked_list.cc)
#target_include_directories(middle_of_the_linked_list PRIVATE Boost::unit_test_framework)

#add_executable(odd_even_linked_list "tst/odd_even_linked_list.cc" src/leetcode/odd_even_linked_list.cc)
#target_include_directories(odd_even_linked_list PRIVATE Boost::unit_test_framework)

#add_executable(range_sum_of_bst "tst/range_sum_of_bst.cc" src/leetcode/range_sum_of_bst.cc)
#target_include_directories(range_sum_of_bst PRIVATE Boost::unit_test_framework)

#add_executable(leaf_similar_trees "tst/leaf_similar_trees.cc" src/leetcode/leaf_similar_trees.cc)
#target_include_directories(leaf_similar_trees PRIVATE Boost::unit_test_framework)

#add_executable(maximum_difference_between_node_and_ancestor "tst/maximum_difference_between_node_and_ancestor.cc" src/leetcode/maximum_difference_between_node_and_ancestor.cc)
#target_include_directories(maximum_difference_between_node_and_ancestor PRIVATE Boost::unit_test_framework)

#add_executable(maximum_product_of_splitted_binary_tree "tst/maximum_product_of_splitted_binary_tree.cc" src/leetcode/maximum_product_of_splitted_binary_tree.cc)
#target_include_directories(maximum_product_of_splitted_binary_tree PRIVATE Boost::unit_test_framework)

#add_executable(binary_tree_maximum_path_sum "tst/binary_tree_maximum_path_sum.cc" src/leetcode/binary_tree_maximum_path_sum.cc)
#target_include_directories(binary_tree_maximum_path_sum PRIVATE Boost::unit_test_framework)

#add_executable(climbing_stairs "tst/climbing_stairs.cc" src/leetcode/climbing_stairs.cc)
#target_include_directories(climbing_stairs PRIVATE Boost::unit_test_framework)

#add_executable(minimum_falling_path_sum "tst/minimum_falling_path_sum.cc" src/leetcode/minimum_falling_path_sum.cc)
#target_include_directories(minimum_falling_path_sum PRIVATE Boost::unit_test_framework)

#add_executable(surrounded_regions "tst/surrounded_regions.cc" src/leetcode/surrounded_regions.cc)
#target_include_directories(surrounded_regions PRIVATE Boost::unit_test_framework)

#add_executable(house_robber "tst/house_robber.cc" src/leetcode/house_robber.cc)
#target_include_directories(house_robber PRIVATE Boost::unit_test_framework)

add_executable(longest_common_subsequence "tst/longest_common_subsequence.cc" src/leetcode/longest_common_subsequence.cc)
target_include_directories(longest_common_subsequence PRIVATE Boost::unit_test_framework)

#add_executable(implement_queue_using_stacks "tst/implement_queue_using_stacks.cc" src/leetcode/implement_queue_using_stacks.cc)
#target_include_directories(implement_queue_using_stacks PRIVATE Boost::unit_test_framework)

#add_executable(evaluate_reverse_polish_notation "tst/evaluate_reverse_polish_notation.cc" src/leetcode/evaluate_reverse_polish_notation.cc)
#target_include_directories(evaluate_reverse_polish_notation PRIVATE Boost::unit_test_framework)

#add_executable(longest_palindromic_subsequence "tst/longest_palindromic_subsequence.cc" src/leetcode/aaa_empty.cc)
#target_include_directories(longest_palindromic_subsequence PRIVATE Boost::unit_test_framework)

#add_executable(evaluate_the_bracket_pairs_of_a_string "tst/evaluate_the_bracket_pairs_of_a_string.cc" src/leetcode/evaluate_the_bracket_pairs_of_a_string.cc)
#target_include_directories(evaluate_the_bracket_pairs_of_a_string PRIVATE Boost::unit_test_framework)

#add_executable(delete_and_earn "tst/delete_and_earn.cc" src/leetcode/delete_and_earn.cc)
#target_include_directories(delete_and_earn PRIVATE Boost::unit_test_framework)

#add_executable(find_if_path_exists_in_graph "tst/find_if_path_exists_in_graph.cc" src/leetcode/find_if_path_exists_in_graph.cc)
#target_include_directories(find_if_path_exists_in_graph PRIVATE Boost::unit_test_framework)

#add_executable(keys_and_rooms "tst/keys_and_rooms.cc" src/leetcode/keys_and_rooms.cc)
#target_include_directories(keys_and_rooms PRIVATE Boost::unit_test_framework)

#add_executable(sum_game "tst/sum_game.cc" src/leetcode/sum_game.cc)
#target_include_directories(sum_game PRIVATE Boost::unit_test_framework)

add_executable(possible_bipartition "tst/possible_bipartition.cc" src/leetcode/possible_bipartition.cc)
target_include_directories(possible_bipartition PRIVATE Boost::unit_test_framework)

add_executable(sum_of_distances_in_tree "tst/sum_of_distances_in_tree.cc" src/leetcode/sum_of_distances_in_tree.cc)
target_include_directories(sum_of_distances_in_tree PRIVATE Boost::unit_test_framework)

add_executable(best_time_to_buy_and_sell_stock_with_cooldown "tst/best_time_to_buy_and_sell_stock_with_cooldown.cc" src/leetcode/best_time_to_buy_and_sell_stock_with_cooldown.cc)
target_include_directories(best_time_to_buy_and_sell_stock_with_cooldown PRIVATE Boost::unit_test_framework)

#add_executable(domino_and_tromino_tiling "tst/domino_and_tromino_tiling.cc" src/leetcode/domino_and_tromino_tiling.cc)
#target_include_directories(domino_and_tromino_tiling PRIVATE Boost::unit_test_framework)

#add_executable(longest_subsequence_with_limited_sum "tst/longest_subsequence_with_limited_sum.cc" src/leetcode/longest_subsequence_with_limited_sum.cc)
#target_include_directories(longest_subsequence_with_limited_sum PRIVATE Boost::unit_test_framework)

#add_executable(jump_game "tst/jump_game.cc" src/leetcode/jump_game.cc)
#target_include_directories(jump_game PRIVATE Boost::unit_test_framework)

#add_executable(maximum_bags_with_full_capacity_of_rocks "tst/maximum_bags_with_full_capacity_of_rocks.cc" src/leetcode/maximum_bags_with_full_capacity_of_rocks.cc)
#target_include_directories(maximum_bags_with_full_capacity_of_rocks PRIVATE Boost::unit_test_framework)

#add_executable(remove_stones_to_minimize_the_total "tst/remove_stones_to_minimize_the_total.cc" src/leetcode/remove_stones_to_minimize_the_total.cc)
#target_include_directories(remove_stones_to_minimize_the_total PRIVATE Boost::unit_test_framework)

#add_executable(delete_node_in_a_linked_list "tst/delete_node_in_a_linked_list.cc" src/leetcode/delete_node_in_a_linked_list.cc)
#target_include_directories(delete_node_in_a_linked_list PRIVATE Boost::unit_test_framework)

add_executable(single_threaded_cpu "tst/single_threaded_cpu.cc" src/leetcode/single_threaded_cpu.cc)
target_include_directories(single_threaded_cpu PRIVATE Boost::unit_test_framework)

#add_executable(all_paths_from_source_to_target "tst/all_paths_from_source_to_target.cc" src/leetcode/all_paths_from_source_to_target.cc)
#target_include_directories(all_paths_from_source_to_target PRIVATE Boost::unit_test_framework)

#add_executable(subsets_ii "tst/subsets_ii.cc" src/leetcode/subsets_ii.cc)
#target_include_directories(subsets_ii PRIVATE Boost::unit_test_framework)

#add_executable(unique_paths_iii "tst/unique_paths_iii.cc" src/leetcode/unique_paths_iii.cc)
#target_include_directories(unique_paths_iii PRIVATE Boost::unit_test_framework)

#add_executable(distribute_candies "tst/distribute_candies.cc" src/leetcode/distribute_candies.cc)
#target_include_directories(distribute_candies PRIVATE Boost::unit_test_framework)

#add_executable(word_pattern "tst/word_pattern.cc" src/leetcode/word_pattern.cc)
#target_include_directories(word_pattern PRIVATE Boost::unit_test_framework)

#add_executable(contains_duplicate_iii "tst/contains_duplicate_iii.cc" src/leetcode/contains_duplicate_iii.cc)
#target_include_directories(contains_duplicate_iii PRIVATE Boost::unit_test_framework)

#add_executable(detect_capital "tst/detect_capital.cc" src/leetcode/detect_capital.cc)
#target_include_directories(detect_capital PRIVATE Boost::unit_test_framework)

add_executable(find_palindrome_with_fixed_length "tst/find_palindrome_with_fixed_length.cc" src/leetcode/find_palindrome_with_fixed_length.cc)
target_include_directories(find_palindrome_with_fixed_length PRIVATE Boost::unit_test_framework)

#add_executable(delete_columns_to_make_sorted "tst/delete_columns_to_make_sorted.cc" src/leetcode/delete_columns_to_make_sorted.cc)
#target_include_directories(delete_columns_to_make_sorted PRIVATE Boost::unit_test_framework)

#add_executable(contains_duplicate "tst/contains_duplicate.cc" src/leetcode/contains_duplicate.cc)
#target_include_directories(contains_duplicate PRIVATE Boost::unit_test_framework)

#add_executable(maximum_subarray "tst/maximum_subarray.cc" src/leetcode/maximum_subarray.cc)
#target_include_directories(maximum_subarray PRIVATE Boost::unit_test_framework)

#add_executable(minimum_rounds_to_complete_all_tasks "tst/minimum_rounds_to_complete_all_tasks.cc" src/leetcode/minimum_rounds_to_complete_all_tasks.cc)
#target_include_directories(minimum_rounds_to_complete_all_tasks PRIVATE Boost::unit_test_framework)

#add_executable(merge_sorted_array "tst/merge_sorted_array.cc" src/leetcode/merge_sorted_array.cc)
#target_include_directories(merge_sorted_array PRIVATE Boost::unit_test_framework)

#add_executable(minimum_number_of_arrows_to_burst_balloons "tst/minimum_number_of_arrows_to_burst_balloons.cc" src/leetcode/minimum_number_of_arrows_to_burst_balloons.cc)
#target_include_directories(minimum_number_of_arrows_to_burst_balloons PRIVATE Boost::unit_test_framework)

#add_executable(intersection_of_two_arrays_ii "tst/intersection_of_two_arrays_ii.cc" src/leetcode/aaa_empty.cc)
#target_include_directories(intersection_of_two_arrays_ii PRIVATE Boost::unit_test_framework)

#add_executable(best_time_to_buy_and_sell_stock "tst/best_time_to_buy_and_sell_stock.cc" src/leetcode/best_time_to_buy_and_sell_stock.cc)
#target_include_directories(best_time_to_buy_and_sell_stock PRIVATE Boost::unit_test_framework)

#add_executable(maximum_ice_cream_bars "tst/maximum_ice_cream_bars.cc" src/leetcode/maximum_ice_cream_bars.cc)
#target_include_directories(maximum_ice_cream_bars PRIVATE Boost::unit_test_framework)

#add_executable(reshape_the_matrix "tst/reshape_the_matrix.cc" src/leetcode/reshape_the_matrix.cc)
#target_include_directories(reshape_the_matrix PRIVATE Boost::unit_test_framework)

#add_executable(pascals_triangle "tst/pascals_triangle.cc" src/leetcode/pascals_triangle.cc)
#target_include_directories(pascals_triangle PRIVATE Boost::unit_test_framework)

#add_executable(pascals_triangle_ii "tst/pascals_triangle_ii.cc" src/leetcode/pascals_triangle_ii.cc)
#target_include_directories(pascals_triangle_ii PRIVATE Boost::unit_test_framework)

#add_executable(gas_station "tst/gas_station.cc" src/leetcode/gas_station.cc)
#target_include_directories(gas_station PRIVATE Boost::unit_test_framework)

#add_executable(search_a_2d_matrix "tst/search_a_2d_matrix.cc" src/leetcode/search_a_2d_matrix.cc)
#target_include_directories(search_a_2d_matrix PRIVATE Boost::unit_test_framework)

add_executable(max_points_on_a_line "tst/max_points_on_a_line.cc" src/leetcode/max_points_on_a_line.cc)
target_include_directories(max_points_on_a_line PRIVATE Boost::unit_test_framework)

#add_executable(first_unique_character_in_a_string "tst/first_unique_character_in_a_string.cc" src/leetcode/first_unique_character_in_a_string.cc)
#target_include_directories(first_unique_character_in_a_string PRIVATE Boost::unit_test_framework)

#add_executable(ransom_note "tst/ransom_note.cc" src/leetcode/ransom_note.cc)
#target_include_directories(ransom_note PRIVATE Boost::unit_test_framework)

#add_executable(valid_anagram "tst/valid_anagram.cc" src/leetcode/valid_anagram.cc)
#target_include_directories(valid_anagram PRIVATE Boost::unit_test_framework)

#add_executable(binary_tree_preorder_traversal "tst/binary_tree_preorder_traversal.cc" src/leetcode/binary_tree_preorder_traversal.cc)
#target_include_directories(binary_tree_preorder_traversal PRIVATE Boost::unit_test_framework)

#add_executable(linked_list_cycle "tst/linked_list_cycle.cc" src/leetcode/linked_list_cycle.cc)
#target_include_directories(linked_list_cycle PRIVATE Boost::unit_test_framework)

#add_executable(merge_two_sorted_lists "tst/merge_two_sorted_lists.cc" src/leetcode/merge_two_sorted_lists.cc)
#target_include_directories(merge_two_sorted_lists PRIVATE Boost::unit_test_framework)

add_executable(sort_list "tst/sort_list.cc" src/leetcode/sort_list.cc)
target_include_directories(sort_list PRIVATE Boost::unit_test_framework)

#add_executable(same_tree "tst/same_tree.cc" src/leetcode/same_tree.cc)
#target_include_directories(same_tree PRIVATE Boost::unit_test_framework)

#add_executable(reverse_linked_list "tst/reverse_linked_list.cc" src/leetcode/reverse_linked_list.cc)
#target_include_directories(reverse_linked_list PRIVATE Boost::unit_test_framework)

add_executable(aaa_empty "tst/aaa_empty.cc" src/leetcode/aaa_empty.cc)
target_include_directories(aaa_empty PRIVATE Boost::unit_test_framework)
