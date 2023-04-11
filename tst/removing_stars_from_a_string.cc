#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/removing_stars_from_a_string.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.removeStars("leet**cod*e");

  // assert
  BOOST_CHECK_EQUAL("lecoe", res);
}
#endif  // !CASE_1
