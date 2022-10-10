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
    
add_executable(CppSamples src/main.cpp)
target_link_libraries(CppSamples)

add_executable(redistribute_characters_to_make_all_strings_equal "tst/redistribute_characters_to_make_all_strings_equal.cc" src/leetcode/redistribute_characters_to_make_all_strings_equal.cc)
target_include_directories(redistribute_characters_to_make_all_strings_equal PRIVATE Boost::unit_test_framework)

add_executable(find-median-from-data-stream "tst/find-median-from-data-stream.cc" src/leetcode/find-median-from-data-stream.cc)
target_include_directories(find-median-from-data-stream PRIVATE Boost::unit_test_framework)
