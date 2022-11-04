#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/reverse_vowels_of_a_string.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string s("hello");

  // act
  auto res = solution.reverseVowels(s);

  // assert
  BOOST_CHECK_EQUAL("holle", res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::string s("leetcode");

  // act
  auto res = solution.reverseVowels(s);

  // assert
  BOOST_CHECK_EQUAL("leotcede", res);
}
