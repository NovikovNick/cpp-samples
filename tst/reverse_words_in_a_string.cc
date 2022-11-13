#define BOOST_TEST_MODULE SolutionTest
#define CASE_3 1
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/reverse_words_in_a_string.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.reverseWords("the sky is blue");

  // assert
  BOOST_CHECK_EQUAL("blue is sky the", res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.reverseWords("  hello world  ");

  // assert
  BOOST_CHECK_EQUAL("world hello", res);
}
#endif  // !CASE_2


#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.reverseWords("a good   example");

  // assert
  BOOST_CHECK_EQUAL("example good a", res);
}
#endif  // !CASE_3