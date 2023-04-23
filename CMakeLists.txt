cmake_minimum_required (VERSION 3.14)
project (CppSamples)

add_subdirectory(external)
enable_testing()

set(BOOST_ROOT "C:\\local\\boost_1_80_0")
set(Boost_DEBUG ON)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
add_definitions( -DBOOST_ALL_NO_LIB )
add_definitions( -DBOOST_ALL_DYN_LINK )

add_subdirectory("src")
add_subdirectory("c_library")

include_directories(${Boost_INCLUDE_DIRS})

file(GLOB CPP_SAMPLES_UTIL "src/util/*.h" "src/util/*.cc")
file(GLOB SOCKET "src/socket/**/*.h" "src/socket/**/*.cc")
file(GLOB CONCURRENCY "src/concurrency/**/*.h" "src/concurrency/**/*.cc")
file(GLOB GAME_SAMPLE "src/snake_game_sample/*.h" "src/snake_game_sample/*.cc")
set(STUN_SRC 
	"src/stun/packet.h"
	"src/stun/stun_client.h"
	"src/stun/stun_client.cc")

add_executable(main src/main.cpp ${SOCKET} ${CONCURRENCY} ${GAME_SAMPLE})
target_compile_features(main PUBLIC cxx_std_20)
target_include_directories(main INTERFACE external/boost)
target_link_libraries(main PRIVATE boost_ext::sml sample::c_lib)
if(WIN32)
  target_link_libraries(main PRIVATE wsock32 ws2_32)
endif()

add_executable(stun src/stun.cpp ${STUN_SRC} ${CPP_SAMPLES_UTIL})
target_compile_features(stun PUBLIC cxx_std_20)
target_link_libraries(stun PRIVATE winmm.lib ws2_32.lib)
set_target_properties(stun 
    PROPERTIES
        OUTPUT_NAME "stun-client-0.0.1")

add_executable(longest_common_subsequence "tst/longest_common_subsequence.cc" src/leetcode/longest_common_subsequence.cc)
target_include_directories(longest_common_subsequence PRIVATE Boost::unit_test_framework)

add_executable(possible_bipartition "tst/possible_bipartition.cc" src/leetcode/possible_bipartition.cc)
target_include_directories(possible_bipartition PRIVATE Boost::unit_test_framework)

add_executable(sum_of_distances_in_tree "tst/sum_of_distances_in_tree.cc" src/leetcode/sum_of_distances_in_tree.cc)
target_include_directories(sum_of_distances_in_tree PRIVATE Boost::unit_test_framework)

add_executable(best_time_to_buy_and_sell_stock_with_cooldown "tst/best_time_to_buy_and_sell_stock_with_cooldown.cc" src/leetcode/best_time_to_buy_and_sell_stock_with_cooldown.cc)
target_include_directories(best_time_to_buy_and_sell_stock_with_cooldown PRIVATE Boost::unit_test_framework)

add_executable(single_threaded_cpu "tst/single_threaded_cpu.cc" src/leetcode/single_threaded_cpu.cc)
target_include_directories(single_threaded_cpu PRIVATE Boost::unit_test_framework)

add_executable(find_palindrome_with_fixed_length "tst/find_palindrome_with_fixed_length.cc" src/leetcode/find_palindrome_with_fixed_length.cc)
target_include_directories(find_palindrome_with_fixed_length PRIVATE Boost::unit_test_framework)

add_executable(max_points_on_a_line "tst/max_points_on_a_line.cc" src/leetcode/max_points_on_a_line.cc)
target_include_directories(max_points_on_a_line PRIVATE Boost::unit_test_framework)

add_executable(binary_tree_preorder_traversal "tst/binary_tree_preorder_traversal.cc" src/leetcode/binary_tree_preorder_traversal.cc)
target_include_directories(binary_tree_preorder_traversal PRIVATE Boost::unit_test_framework)

add_executable(sort_list "tst/sort_list.cc" src/leetcode/sort_list.cc)
target_include_directories(sort_list PRIVATE Boost::unit_test_framework)

add_executable(flip_string_to_monotone_increasing "tst/flip_string_to_monotone_increasing.cc" src/leetcode/flip_string_to_monotone_increasing.cc)
target_include_directories(flip_string_to_monotone_increasing PRIVATE Boost::unit_test_framework)

add_executable(maximum_sum_circular_subarray "tst/maximum_sum_circular_subarray.cc" src/leetcode/maximum_sum_circular_subarray.cc)
target_include_directories(maximum_sum_circular_subarray PRIVATE Boost::unit_test_framework)

add_executable(subarray_sums_divisible_by_k "tst/subarray_sums_divisible_by_k.cc" src/leetcode/subarray_sums_divisible_by_k.cc)
target_include_directories(subarray_sums_divisible_by_k PRIVATE Boost::unit_test_framework)

add_executable(non_decreasing_subsequences "tst/non_decreasing_subsequences.cc" src/leetcode/non_decreasing_subsequences.cc)
target_include_directories(non_decreasing_subsequences PRIVATE Boost::unit_test_framework)

add_executable(snakes_and_ladders "tst/snakes_and_ladders.cc" src/leetcode/snakes_and_ladders.cc)
target_include_directories(snakes_and_ladders PRIVATE Boost::unit_test_framework)

add_executable(find_closest_node_to_given_two_nodes "tst/find_closest_node_to_given_two_nodes.cc" src/leetcode/find_closest_node_to_given_two_nodes.cc)
target_include_directories(find_closest_node_to_given_two_nodes PRIVATE Boost::unit_test_framework)

add_executable(cheapest_flights_within_k_stops "tst/cheapest_flights_within_k_stops.cc" src/leetcode/cheapest_flights_within_k_stops.cc)
target_include_directories(cheapest_flights_within_k_stops PRIVATE Boost::unit_test_framework)

add_executable(01_matrix "tst/01_matrix.cc" src/leetcode/01_matrix.cc)
target_include_directories(01_matrix PRIVATE Boost::unit_test_framework)

add_executable(concatenated_words "tst/concatenated_words.cc" src/leetcode/concatenated_words.cc)
target_include_directories(concatenated_words PRIVATE Boost::unit_test_framework)

add_executable(data_stream_as_disjoint_intervals "tst/data_stream_as_disjoint_intervals.cc" src/leetcode/data_stream_as_disjoint_intervals.cc)
target_include_directories(data_stream_as_disjoint_intervals PRIVATE Boost::unit_test_framework)

add_executable(best_team_with_no_conflicts "tst/best_team_with_no_conflicts.cc" src/leetcode/best_team_with_no_conflicts.cc)
target_include_directories(best_team_with_no_conflicts PRIVATE Boost::unit_test_framework)

add_executable(query_kth_smallest_trimmed_number "tst/query_kth_smallest_trimmed_number.cc" src/leetcode/query_kth_smallest_trimmed_number.cc)
target_include_directories(query_kth_smallest_trimmed_number PRIVATE Boost::unit_test_framework)

add_executable(naming_a_company "tst/naming_a_company.cc" src/leetcode/naming_a_company.cc)
target_include_directories(naming_a_company PRIVATE Boost::unit_test_framework)

add_executable(capacity_to_ship_packages_within_d_days "tst/capacity_to_ship_packages_within_d_days.cc" src/leetcode/capacity_to_ship_packages_within_d_days.cc)
target_include_directories(capacity_to_ship_packages_within_d_days PRIVATE Boost::unit_test_framework)

add_executable(minimize_deviation_in_array "tst/minimize_deviation_in_array.cc" src/leetcode/minimize_deviation_in_array.cc)
target_include_directories(minimize_deviation_in_array PRIVATE Boost::unit_test_framework)

add_executable(edit_distance "tst/edit_distance.cc" src/leetcode/edit_distance.cc)
target_include_directories(edit_distance PRIVATE Boost::unit_test_framework)

add_executable(find_duplicate_subtrees "tst/find_duplicate_subtrees.cc" src/leetcode/find_duplicate_subtrees.cc)
target_include_directories(find_duplicate_subtrees PRIVATE Boost::unit_test_framework)

add_executable(count_subarrays_with_fixed_bounds "tst/count_subarrays_with_fixed_bounds.cc" src/leetcode/count_subarrays_with_fixed_bounds.cc)
target_include_directories(count_subarrays_with_fixed_bounds PRIVATE Boost::unit_test_framework)

add_executable(jump_game_iv "tst/jump_game_iv.cc" src/leetcode/jump_game_iv.cc)
target_include_directories(jump_game_iv PRIVATE Boost::unit_test_framework)

add_executable(kth_missing_positive_number "tst/kth_missing_positive_number.cc" src/leetcode/kth_missing_positive_number.cc)
target_include_directories(kth_missing_positive_number PRIVATE Boost::unit_test_framework)

add_executable(koko_eating_bananas "tst/koko_eating_bananas.cc" src/leetcode/koko_eating_bananas.cc)
target_include_directories(koko_eating_bananas PRIVATE Boost::unit_test_framework)

add_executable(linked_list_cycle_ii "tst/linked_list_cycle_ii.cc" src/leetcode/linked_list_cycle_ii.cc)
target_include_directories(linked_list_cycle_ii PRIVATE Boost::unit_test_framework)

add_executable(construct_binary_tree_from_inorder_and_postorder_traversal "tst/construct_binary_tree_from_inorder_and_postorder_traversal.cc" src/leetcode/construct_binary_tree_from_inorder_and_postorder_traversal.cc)
target_include_directories(construct_binary_tree_from_inorder_and_postorder_traversal PRIVATE Boost::unit_test_framework)

add_executable(design_add_and_search_words_data_structure "tst/design_add_and_search_words_data_structure.cc" src/leetcode/design_add_and_search_words_data_structure.cc)
target_include_directories(design_add_and_search_words_data_structure PRIVATE Boost::unit_test_framework)

add_executable(number_of_operations_to_make_network_connected "tst/number_of_operations_to_make_network_connected.cc" src/leetcode/number_of_operations_to_make_network_connected.cc)
target_compile_features(number_of_operations_to_make_network_connected PUBLIC cxx_std_20)
target_include_directories(number_of_operations_to_make_network_connected PRIVATE Boost::unit_test_framework)

add_executable(count_unreachable_pairs_of_nodes_in_an_undirected_graph "tst/count_unreachable_pairs_of_nodes_in_an_undirected_graph.cc" src/leetcode/count_unreachable_pairs_of_nodes_in_an_undirected_graph.cc)
target_compile_features(count_unreachable_pairs_of_nodes_in_an_undirected_graph PUBLIC cxx_std_20)
target_include_directories(count_unreachable_pairs_of_nodes_in_an_undirected_graph PRIVATE Boost::unit_test_framework)

add_executable(longest_cycle_in_a_graph "tst/longest_cycle_in_a_graph.cc" src/leetcode/longest_cycle_in_a_graph.cc)
target_compile_features(longest_cycle_in_a_graph PUBLIC cxx_std_20)
target_include_directories(longest_cycle_in_a_graph PRIVATE Boost::unit_test_framework)

add_executable(minimum_path_sum "tst/minimum_path_sum.cc" src/leetcode/minimum_path_sum.cc)
target_compile_features(minimum_path_sum PUBLIC cxx_std_20)
target_include_directories(minimum_path_sum PRIVATE Boost::unit_test_framework)

#add_executable(minimum_cost_for_tickets "tst/minimum_cost_for_tickets.cc" src/leetcode/minimum_cost_for_tickets.cc)
#target_compile_features(minimum_cost_for_tickets PUBLIC cxx_std_20)
#target_include_directories(minimum_cost_for_tickets PRIVATE Boost::unit_test_framework)

#add_executable(reducing_dishes "tst/reducing_dishes.cc" src/leetcode/reducing_dishes.cc)
#target_compile_features(reducing_dishes PUBLIC cxx_std_20)
#target_include_directories(reducing_dishes PRIVATE Boost::unit_test_framework)

add_executable(scramble_string "tst/scramble_string.cc" src/leetcode/scramble_string.cc)
target_compile_features(scramble_string PUBLIC cxx_std_20)
target_include_directories(scramble_string PRIVATE Boost::unit_test_framework)

add_executable(number_of_ways_of_cutting_a_pizza "tst/number_of_ways_of_cutting_a_pizza.cc" src/leetcode/number_of_ways_of_cutting_a_pizza.cc)
target_compile_features(number_of_ways_of_cutting_a_pizza PUBLIC cxx_std_20)
target_include_directories(number_of_ways_of_cutting_a_pizza PRIVATE Boost::unit_test_framework)

#add_executable(k_closest_points_to_origin "tst/k_closest_points_to_origin.cc" src/leetcode/k_closest_points_to_origin.cc)
#target_compile_features(k_closest_points_to_origin PUBLIC cxx_std_20)
#target_include_directories(k_closest_points_to_origin PRIVATE Boost::unit_test_framework)

#add_executable(successful_pairs_of_spells_and_potions "tst/successful_pairs_of_spells_and_potions.cc" src/leetcode/successful_pairs_of_spells_and_potions.cc)
#target_compile_features(successful_pairs_of_spells_and_potions PUBLIC cxx_std_20)
#target_include_directories(successful_pairs_of_spells_and_potions PRIVATE Boost::unit_test_framework)

#add_executable(boats_to_save_people "tst/boats_to_save_people.cc" src/leetcode/boats_to_save_people.cc)
#target_compile_features(boats_to_save_people PUBLIC cxx_std_20)
#target_include_directories(boats_to_save_people PRIVATE Boost::unit_test_framework)

add_executable(optimal_partition_of_string "tst/optimal_partition_of_string.cc" src/leetcode/optimal_partition_of_string.cc)
target_compile_features(optimal_partition_of_string PUBLIC cxx_std_20)
target_include_directories(optimal_partition_of_string PRIVATE Boost::unit_test_framework)

add_executable(minimize_maximum_of_array "tst/minimize_maximum_of_array.cc" src/leetcode/minimize_maximum_of_array.cc)
target_compile_features(minimize_maximum_of_array PUBLIC cxx_std_20)
target_include_directories(minimize_maximum_of_array PRIVATE Boost::unit_test_framework)

#add_executable(number_of_closed_islands "tst/number_of_closed_islands.cc" src/leetcode/number_of_closed_islands.cc)
#target_compile_features(number_of_closed_islands PUBLIC cxx_std_20)
#target_include_directories(number_of_closed_islands PRIVATE Boost::unit_test_framework)

#add_executable(number_of_enclaves "tst/number_of_enclaves.cc" src/leetcode/number_of_enclaves.cc)
#target_compile_features(number_of_enclaves PUBLIC cxx_std_20)
#target_include_directories(number_of_enclaves PRIVATE Boost::unit_test_framework)

#add_executable(clone_graph "tst/clone_graph.cc" src/leetcode/clone_graph.cc)
#target_compile_features(clone_graph PUBLIC cxx_std_20)
#target_include_directories(clone_graph PRIVATE Boost::unit_test_framework)

add_executable(largest_color_value_in_a_directed_graph "tst/largest_color_value_in_a_directed_graph.cc" src/leetcode/largest_color_value_in_a_directed_graph.cc)
target_compile_features(largest_color_value_in_a_directed_graph PUBLIC cxx_std_20)
target_include_directories(largest_color_value_in_a_directed_graph PRIVATE Boost::unit_test_framework)

#add_executable(surface_area_of_3d_shapes "tst/surface_area_of_3d_shapes.cc" src/leetcode/surface_area_of_3d_shapes.cc)
#target_compile_features(surface_area_of_3d_shapes PUBLIC cxx_std_20)
#target_include_directories(surface_area_of_3d_shapes PRIVATE Boost::unit_test_framework)

add_executable(removing_stars_from_a_string "tst/removing_stars_from_a_string.cc" src/leetcode/removing_stars_from_a_string.cc)
target_compile_features(removing_stars_from_a_string PUBLIC cxx_std_20)
target_include_directories(removing_stars_from_a_string PRIVATE Boost::unit_test_framework)

#add_executable(simplify_path "tst/simplify_path.cc" src/leetcode/simplify_path.cc)
#target_compile_features(simplify_path PUBLIC cxx_std_20)
#target_include_directories(simplify_path PRIVATE Boost::unit_test_framework)

#add_executable(validate_stack_sequences "tst/validate_stack_sequences.cc" src/leetcode/validate_stack_sequences.cc)
#target_compile_features(validate_stack_sequences PUBLIC cxx_std_20)
#target_include_directories(validate_stack_sequences PRIVATE Boost::unit_test_framework)

add_executable(mirror_reflection "tst/mirror_reflection.cc" src/leetcode/mirror_reflection.cc)
target_compile_features(mirror_reflection PUBLIC cxx_std_20)
target_include_directories(mirror_reflection PRIVATE Boost::unit_test_framework)

add_executable(number_of_ways_to_form_a_target_string_given_a_dictionary "tst/number_of_ways_to_form_a_target_string_given_a_dictionary.cc" src/leetcode/number_of_ways_to_form_a_target_string_given_a_dictionary.cc)
target_compile_features(number_of_ways_to_form_a_target_string_given_a_dictionary PUBLIC cxx_std_20)
target_include_directories(number_of_ways_to_form_a_target_string_given_a_dictionary PRIVATE Boost::unit_test_framework)

#add_executable(kids_with_the_greatest_number_of_candies "tst/kids_with_the_greatest_number_of_candies.cc" src/leetcode/kids_with_the_greatest_number_of_candies.cc)
#target_compile_features(kids_with_the_greatest_number_of_candies PUBLIC cxx_std_20)
#target_include_directories(kids_with_the_greatest_number_of_candies PRIVATE Boost::unit_test_framework)

#add_executable(merge_strings_alternately "tst/merge_strings_alternately.cc" src/leetcode/merge_strings_alternately.cc)
#target_compile_features(merge_strings_alternately PUBLIC cxx_std_20)
#target_include_directories(merge_strings_alternately PRIVATE Boost::unit_test_framework)

#add_executable(longest_zigzag_path_in_a_binary_tree "tst/longest_zigzag_path_in_a_binary_tree.cc" src/leetcode/longest_zigzag_path_in_a_binary_tree.cc)
#target_compile_features(longest_zigzag_path_in_a_binary_tree PUBLIC cxx_std_20)
#target_include_directories(longest_zigzag_path_in_a_binary_tree PRIVATE Boost::unit_test_framework)

#add_executable(maximum_width_of_binary_tree "tst/maximum_width_of_binary_tree.cc" src/leetcode/maximum_width_of_binary_tree.cc)
#target_compile_features(maximum_width_of_binary_tree PUBLIC cxx_std_20)
#target_include_directories(maximum_width_of_binary_tree PRIVATE Boost::unit_test_framework)

add_executable(profitable_schemes "tst/profitable_schemes.cc" src/leetcode/profitable_schemes.cc)
target_compile_features(profitable_schemes PUBLIC cxx_std_20)
target_include_directories(profitable_schemes PRIVATE Boost::unit_test_framework)

add_executable(minimum_insertion_steps_to_make_a_string_palindrome "tst/minimum_insertion_steps_to_make_a_string_palindrome.cc" src/leetcode/minimum_insertion_steps_to_make_a_string_palindrome.cc)
target_compile_features(minimum_insertion_steps_to_make_a_string_palindrome PUBLIC cxx_std_20)
target_include_directories(minimum_insertion_steps_to_make_a_string_palindrome PRIVATE Boost::unit_test_framework)

add_executable(restore_the_array "tst/restore_the_array.cc" src/leetcode/restore_the_array.cc)
target_compile_features(restore_the_array PUBLIC cxx_std_20)
target_include_directories(restore_the_array PRIVATE Boost::unit_test_framework)

add_executable(aaa_empty "tst/aaa_empty.cc" src/leetcode/aaa_empty.cc)
target_compile_features(aaa_empty PUBLIC cxx_std_20)
target_include_directories(aaa_empty PRIVATE Boost::unit_test_framework)

