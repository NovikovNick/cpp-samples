#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/01_matrix.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> matrix{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  // act
  auto res = solution.updateMatrix(matrix);

  // assert
  for (const auto& row : res) {
    for (const auto col : row) {
      debug("{} ", col);
    }
    debug("\n");
  }
}
#endif  // !CASE_1
