cmake_minimum_required (VERSION 3.25)
project (CppSamples)

if (MSVC)
    # warning level 4
    SET(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /DDEBUG /W4 /GR /EHsc")
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

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
add_subdirectory("template_lib")
add_subdirectory("pimpl")

include_directories(${Boost_INCLUDE_DIRS})

file(GLOB CPP_SAMPLES_UTIL "src/util/*.h" "src/util/*.cc")
file(GLOB SOCKET "src/socket/**/*.h" "src/socket/**/*.cc")
file(GLOB CONCURRENCY "src/concurrency/**/*.h" "src/concurrency/**/*.cc")

set(FEATURES_COMMON "src/cpp_features/common.h" "src/cpp_features/common.cc")
set(FEATURES_EXCEPTION_SAFETY "src/cpp_features/exception_safety.h" "src/cpp_features/exception_safety.cc")


set(STUN_SRC 
	"src/stun/packet.h"
	"src/stun/stun_client.h"
	"src/stun/stun_client.cc")

add_executable(main src/main.cpp 
    ${FEATURES_COMMON} 
    ${FEATURES_EXCEPTION_SAFETY}
)
target_compile_features(main PUBLIC cxx_std_20)
target_link_libraries(main 
    PRIVATE 
        sample::pimpl
        template::lib
        Boost::unit_test_framework
)

add_executable(stun src/stun.cpp ${STUN_SRC} ${CPP_SAMPLES_UTIL})
target_compile_features(stun PUBLIC cxx_std_20)
target_link_libraries(stun PRIVATE winmm.lib ws2_32.lib)
set_target_properties(stun 
    PROPERTIES
        OUTPUT_NAME "stun-client-0.0.1")

set(leetcodeProblems
    unique_paths.cc
    copy_list_with_random_pointer.cc
    split_linked_list_in_parts.cc
    reverse_linked_list_ii.cc
    max_consecutive_ones_iii.cc
    combination_sum_iv.cc
    count_all_valid_pickup_and_delivery_options.cc
    group_the_people_given_the_group_size_they_belong_to.cc
    minimum_deletions_to_make_character_frequencies_unique.cc
    candy.cc
    reconstruct_itinerary.cc
    min_cost_to_connect_all_points.cc
    path_with_minimum_effort.cc
    shortest_path_visiting_all_nodes.cc
    the_k_weakest_rows_in_a_matrix.cc
    find_the_duplicate_number.cc
    minimum_operations_to_reduce_x_to_zero.cc
    median_of_two_sorted_arrays.cc
    is_subsequence.cc
    design_hashmap.cc #!
    longest_string_chain.cc
    champagne_tower.cc
    find_the_difference.cc
    remove_duplicate_letters.cc
    decoded_string_at_index.cc
    sort_array_by_parity.cc
    monotonic_array.cc
    132_pattern.cc
    remove_colored_pieces_if_both_neighbors_are_the_same_color.cc
    number_of_good_pairs.cc
    majority_element_ii.cc
    integer_break.cc
    build_array_where_you_can_find_the_maximum_exactly_k_comparisons.cc
    max_dot_product_of_two_subsequences.cc
    find_first_and_last_position_of_element_in_sorted_array.cc
)

foreach(leetcodeProblem ${leetcodeProblems})

get_filename_component(problemFilename "${leetcodeProblem}" NAME_WLE)
  
add_executable(${problemFilename} "tst/${leetcodeProblem}" "src/leetcode/${leetcodeProblem}")
target_compile_features(${problemFilename} PUBLIC cxx_std_20)
target_include_directories(${problemFilename} PRIVATE Boost::unit_test_framework)

endforeach()
