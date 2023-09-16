#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/path_with_minimum_effort.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> heights{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};

  // act
  auto res = solution.minimumEffortPath(heights);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
