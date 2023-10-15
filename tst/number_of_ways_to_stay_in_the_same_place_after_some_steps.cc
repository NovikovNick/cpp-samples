#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/number_of_ways_to_stay_in_the_same_place_after_some_steps.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int steps = 3, arrLen = 2;

  // act
  auto res = solution.numWays(steps, arrLen);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
