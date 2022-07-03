cmake_minimum_required (VERSION 3.8)
project (CppSamples)

enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(Boost_DEBUG ON)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
add_definitions( -DBOOST_ALL_NO_LIB )
add_definitions( -DBOOST_ALL_DYN_LINK )

add_subdirectory("src")

    
include_directories(${Boost_INCLUDE_DIRS})
    
add_executable(CppSamples src/main.cpp src/Formula.cpp src/Formula.h)
target_link_libraries(CppSamples Boost::boost)
    
add_executable(test_executable tst/solution_test.cpp src/Formula.cpp src/Formula.h)
target_include_directories(test_executable PRIVATE Boost::unit_test_framework)
    
message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
message(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")

add_test(NAME test1 COMMAND test_executable)