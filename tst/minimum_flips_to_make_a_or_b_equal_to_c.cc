#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_flips_to_make_a_or_b_equal_to_c.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.minFlips(8, 3, 5);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1
