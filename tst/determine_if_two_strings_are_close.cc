#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/determine_if_two_strings_are_close.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string word1("cabbba");
  std::string word2("aabbss");

  // act
  auto res = solution.closeStrings(word1, word2);

  // assert
  BOOST_CHECK(!res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string word1("svotbsgqiqmeqjwdqqtkucrzqphqxqtqqlyfan");
  std::string word2("aapyhufaaaalkqsvtjnaaoewxkrgsbsazadmci");

  // act
  auto res = solution.closeStrings(word1, word2);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_2
