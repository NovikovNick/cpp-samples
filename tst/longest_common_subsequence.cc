#define BOOST_TEST_MODULE SolutionTest
#define CASE_4 1
#define CASE_3 1
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/longest_common_subsequence.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string text1("aaaaaaaaaa");
  std::string text2("aaa");

  // act
  auto res = solution.longestCommonSubsequence(text1, text2);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::string text1("cccaaa");
  std::string text2("cffffffffffffffffffffffa");

  // act
  auto res = solution.longestCommonSubsequence(text1, text2);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::string text1("mhunuzqrkzsnidwbun");
  std::string text2("szulspmhwpazoxijwbq");

  // act
  auto res = solution.longestCommonSubsequence(text1, text2);

  // assert
  BOOST_CHECK_EQUAL(6, res);
}
#endif  // !CASE_3

#if CASE_4
BOOST_AUTO_TEST_CASE(case4) {
  // arrange
  leetcode::Solution solution;
  std::string text1("abc");
  std::string text2("dac");

  // act
  auto res = solution.longestCommonSubsequence(text1, text2);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_3