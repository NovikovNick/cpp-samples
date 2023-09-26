#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/remove_duplicate_letters.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s = "cbacdcbc";

  // act
  auto res = solution.removeDuplicateLetters(s);

  // assert
  BOOST_CHECK_EQUAL("cbacdcbc", res);
}
#endif  // !CASE_1
