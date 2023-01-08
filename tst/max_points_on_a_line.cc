#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/max_points_on_a_line.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> points{{1, 1}, {3, 2}, {5, 3},
                                       {4, 1}, {2, 3}, {1, 4}};
  // act
  auto res = solution.maxPoints(points);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
