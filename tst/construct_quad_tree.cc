#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/construct_quad_tree.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid{
      {0, 0, 0, 0, 1, 1, 0, 0},
      {0, 0, 0, 0, 1, 1, 0, 0},
      {1, 1, 0, 0, 1, 1, 1, 1},
      {1, 1, 0, 0, 1, 1, 1, 1},
      {1, 1, 0, 0, 1, 1, 1, 1},
      {1, 1, 0, 0, 1, 1, 1, 1},
      {1, 1, 0, 0, 0, 0, 1, 1},
      {1, 1, 0, 0, 0, 0, 1, 1}};

  // act
  auto res = solution.construct(grid);

  // assert
  debug("{}\n", res->val);
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
