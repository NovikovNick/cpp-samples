#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/greatest_common_divisor_of_strings.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.gcdOfStrings("ABABAB", "AB");

  // assert
  BOOST_CHECK_EQUAL("AB", res);
}
#endif  // !CASE_1
