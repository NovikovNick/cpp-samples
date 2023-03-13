#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/projection_area_of_3d_shapes.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid{{1, 2}, {3, 4}};

  // act
  auto res = solution.projectionArea(grid);

  // assert
  BOOST_CHECK_EQUAL(17, res);
}
#endif  // !CASE_1
