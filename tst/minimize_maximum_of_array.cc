#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define DEBUG 0

#include "../src/leetcode/minimize_maximum_of_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <chrono>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 2};

  using namespace std::chrono;
  auto started = steady_clock::now();

  // act & assert
  for (int i = 3; i < 1e5; ++i) {
    BOOST_CHECK_EQUAL(solution.bruteforce(nums),
                      solution.minimizeArrayValue(nums));
    // std::cout << i << std::endl;
  }
  auto ended = steady_clock::now();
  auto elapsed = duration_cast<milliseconds>(ended - started).count();
  std::cout << std::format("Execution time: {}ms\n", elapsed);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{6, 9, 3, 8, 14};

  using namespace std::chrono;
  auto started = steady_clock::now();

  // act & assert
  BOOST_CHECK_EQUAL(8, solution.minimizeArrayValue(nums));
  auto ended = steady_clock::now();
  auto elapsed = duration_cast<milliseconds>(ended - started).count();
  std::cout << std::format("Execution time: {}ms\n", elapsed);
}
#endif  // !CASE_2