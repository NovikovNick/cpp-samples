#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/reverse_words_in_a_string_iii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.reverseWords("Let's take LeetCode contest");

  // assert
  BOOST_CHECK_EQUAL("s'teL ekat edoCteeL tsetnoc", res);
}
#endif  // !CASE_1
