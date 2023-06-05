#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/check_if_it_is_a_straight_line.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> coordinates {
    {0, 0}, {0, 1}, { 0, -1 }
  };


  // act
  auto res = solution.checkStraightLine(coordinates);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
