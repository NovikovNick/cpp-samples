#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/surface_area_of_3d_shapes.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid{{2, 1}, {0, 0}};

  // act
  auto res = solution.surfaceArea(grid);

  // assert
  BOOST_CHECK_EQUAL(14, res);
}
#endif  // !CASE_1
