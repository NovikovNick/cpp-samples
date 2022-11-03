#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/longest_palindrome_by_concatenating_two_letter_words.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words = {"lc", "cl", "gg"};

  // act
  auto res = solution.longestPalindrome(words);

  // assert
  BOOST_CHECK_EQUAL(6, res);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words = {"ab", "ty", "yt", "lc", "cl", "ab"};

  // act
  auto res = solution.longestPalindrome(words);

  // assert
  BOOST_CHECK_EQUAL(8, res);
}

BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words = {"cc", "ll", "xx"};

  // act
  auto res = solution.longestPalindrome(words);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}

BOOST_AUTO_TEST_CASE(case4) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words = {"em", "pe", "mp", "ee", "pp",
                                    "me", "ep", "em", "em", "me"};

  // act
  auto res = solution.longestPalindrome(words);

  // assert
  BOOST_CHECK_EQUAL(14, res);
}
