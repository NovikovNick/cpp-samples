#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/simplify_path.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.simplifyPath("/a//b////c/d//././/..");

  // assert
  BOOST_CHECK_EQUAL("/a/b/c", res);
}
#endif  // !CASE_1
