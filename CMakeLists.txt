﻿cmake_minimum_required (VERSION 3.25)
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
    design_hashmap.cc #!
    backspace_string_compare.cc
    constrained_subsequence_sum.cc
    maximum_score_of_a_good_subarray.cc
    power_of_four.cc
    find_largest_value_in_each_tree_row.cc
)

foreach(leetcodeProblem ${leetcodeProblems})

get_filename_component(problemFilename "${leetcodeProblem}" NAME_WLE)
  
add_executable(${problemFilename} "tst/${leetcodeProblem}" "src/leetcode/${leetcodeProblem}")
target_compile_features(${problemFilename} PUBLIC cxx_std_20)
target_include_directories(${problemFilename} PRIVATE Boost::unit_test_framework)

endforeach()
