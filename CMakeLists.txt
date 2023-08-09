cmake_minimum_required (VERSION 3.14)
project (CppSamples)

add_subdirectory(external)
enable_testing()

set(BOOST_ROOT "C:\\local\\boost_1_80_0")
set(Boost_DEBUG ON)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
add_definitions( -DBOOST_ALL_NO_LIB )
add_definitions( -DBOOST_ALL_DYN_LINK )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

add_subdirectory("src")
add_subdirectory("c_library")
add_subdirectory("dll_sample")

include_directories(${Boost_INCLUDE_DIRS})

file(GLOB CPP_SAMPLES_UTIL "src/util/*.h" "src/util/*.cc")
file(GLOB TEMPLATE_SRC "src/template/*.h" "src/template/*.cc")
file(GLOB SOCKET "src/socket/**/*.h" "src/socket/**/*.cc")
file(GLOB CONCURRENCY "src/concurrency/**/*.h" "src/concurrency/**/*.cc")
file(GLOB GAME_SAMPLE "src/snake_game_sample/*.h" "src/snake_game_sample/*.cc")
set(STUN_SRC 
	"src/stun/packet.h"
	"src/stun/stun_client.h"
	"src/stun/stun_client.cc")

add_executable(main src/main.cpp ${SOCKET} ${CONCURRENCY} ${GAME_SAMPLE} ${TEMPLATE_SRC})
target_compile_features(main PUBLIC cxx_std_20)
target_include_directories(main INTERFACE external/boost)
target_link_libraries(main 
    PRIVATE 
        boost_ext::sml
        sample::c_lib
        sample::dll
)
if(WIN32)
  target_link_libraries(main PRIVATE wsock32 ws2_32)
endif()

add_executable(stun src/stun.cpp ${STUN_SRC} ${CPP_SAMPLES_UTIL})
target_compile_features(stun PUBLIC cxx_std_20)
target_link_libraries(stun PRIVATE winmm.lib ws2_32.lib)
set_target_properties(stun 
    PROPERTIES
        OUTPUT_NAME "stun-client-0.0.1")

set(leetcodeProblems
    longest_common_subsequence.cc
    possible_bipartition.cc
    sum_of_distances_in_tree.cc
    best_time_to_buy_and_sell_stock_with_cooldown.cc
    single_threaded_cpu.cc
    find_palindrome_with_fixed_length.cc
    max_points_on_a_line.cc
    binary_tree_preorder_traversal.cc
    sort_list.cc
    flip_string_to_monotone_increasing.cc
    maximum_sum_circular_subarray.cc
    subarray_sums_divisible_by_k.cc
    non_decreasing_subsequences.cc
    snakes_and_ladders.cc
    find_closest_node_to_given_two_nodes.cc
    cheapest_flights_within_k_stops.cc
    01_matrix.cc
    concatenated_words.cc
    data_stream_as_disjoint_intervals.cc
    best_team_with_no_conflicts.cc
    query_kth_smallest_trimmed_number.cc
    naming_a_company.cc
    capacity_to_ship_packages_within_d_days.cc
    minimize_deviation_in_array.cc
    jump_game_iv.cc
    edit_distance.cc
    find_duplicate_subtrees.cc
    count_subarrays_with_fixed_bounds.cc
    kth_missing_positive_number.cc
    koko_eating_bananas.cc
    linked_list_cycle_ii.cc
    construct_binary_tree_from_inorder_and_postorder_traversal.cc
    design_add_and_search_words_data_structure.cc
    number_of_operations_to_make_network_connected.cc
    count_unreachable_pairs_of_nodes_in_an_undirected_graph.cc
    longest_cycle_in_a_graph.cc
    minimum_path_sum.cc
    scramble_string.cc
    number_of_ways_of_cutting_a_pizza.cc
    optimal_partition_of_string.cc
    minimize_maximum_of_array.cc
    largest_color_value_in_a_directed_graph.cc
    removing_stars_from_a_string.cc
    mirror_reflection.cc
    number_of_ways_to_form_a_target_string_given_a_dictionary.cc
    profitable_schemes.cc
    minimum_insertion_steps_to_make_a_string_palindrome.cc
    restore_the_array.cc
    checking_existence_of_edge_length_limited_paths.cc
    find_the_difference_of_two_arrays.cc
    dota2_senate.cc
    number_of_subsequences_that_satisfy_the_given_sum_condition.cc
    find_the_longest_valid_obstacle_course_at_each_position.cc
    uncrossed_lines.cc
    solving_questions_with_brainpower.cc
    shortest_bridge.cc
    stone_game_ii.cc
    design_underground_system.cc
    shortest_path_in_binary_matrix.cc
    check_if_it_is_a_straight_line.cc
    maximum_value_at_a_given_index_in_a_bounded_array.cc
    snapshot_array.cc
    largest_triangle_area.cc
    best_time_to_buy_and_sell_stock_with_transaction_fee.cc
    longest_arithmetic_subsequence.cc
    count_all_possible_routes.cc
    find_k_pairs_with_smallest_sums.cc
    path_with_maximum_probability.cc
    last_day_where_you_can_still_cross.cc
    fair_distribution_of_cookies.cc
    maximum_number_of_achievable_transfer_requests.cc
    single_number_ii.cc
    maximize_the_confusion_of_an_exam.cc
    put_marbles_in_bags.cc
    substring_with_largest_variance.cc
    find_eventual_safe_states.cc
    course_schedule.cc
    maximum_number_of_events_that_can_be_attended_ii.cc
    smallest_sufficient_team.cc
    lru_cache.cc
    non_overlapping_intervals.cc
    number_of_longest_increasing_subsequence.cc
    knight_probability_in_chessboard.cc
    all_possible_full_binary_trees.cc
    minimum_speed_to_arrive_on_time.cc
    maximum_running_time_of_n_computers.cc
    soup_servings.cc
    strange_printer.cc
    minimum_ascii_delete_sum_for_two_strings.cc
    word_break.cc
    unique_binary_search_trees_ii.cc
    number_of_music_playlists.cc
    minimize_the_maximum_difference_of_pairs.cc
)

foreach(leetcodeProblem ${leetcodeProblems})

get_filename_component(problemFilename "${leetcodeProblem}" NAME_WLE)
  
add_executable(${problemFilename} "tst/${leetcodeProblem}" "src/leetcode/${leetcodeProblem}")
target_compile_features(${problemFilename} PUBLIC cxx_std_20)
target_include_directories(${problemFilename} PRIVATE Boost::unit_test_framework)

endforeach()
