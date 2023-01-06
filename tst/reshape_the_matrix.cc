#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/reshape_the_matrix.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> mat{{1, 2}, {3, 4}};
  auto res = solution.matrixReshape(mat, 1, 4);

  // assert
  for (const auto& row : res) {
    for (const auto& col : row) {
      debug("{:4d}", col);
    }
    debug("\n");
  }
}
#endif  // !CASE_1
