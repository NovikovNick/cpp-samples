#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/spiral_matrix.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  // std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // std::vector<std::vector<int>> matrix{{1, 2}, {4, 5}};
  std::vector<std::vector<int>> matrix{
      {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};

  // act
  auto res = solution.spiralOrder(matrix);

  // assert
  for (const auto it : res) {
    debug("{} ", it);
  }
  debug("\n");

  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
