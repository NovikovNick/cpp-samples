#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_the_difference.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s = "abcd", t = "abcde";

  // act
  auto res = solution.findTheDifference(s, t);

  // assert
  BOOST_CHECK_EQUAL('e', res);
}
#endif  // !CASE_1
