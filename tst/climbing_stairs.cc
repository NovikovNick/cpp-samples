#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/climbing_stairs.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  for (int i = 1; i <= 45; ++i) {
    auto res = solution.climbStairs(i);

  }
  // assert
  // BOOST_CHECK_EQUAL(42, res);
  
}
#endif  // !CASE_1
