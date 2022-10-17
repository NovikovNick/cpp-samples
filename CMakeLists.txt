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
