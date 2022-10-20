#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/can_make_palindrome_from_substring.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> queries{
      {3, 3, 0}, {1, 2, 0}, 
      {0, 3, 1}, 
      {0, 3, 2}, {0, 4, 1}};
  std::string s("abcda");

  // act
  auto res = solution.canMakePaliQueries(s, queries);

  // assert
  BOOST_CHECK_EQUAL(1, res[0]);
  BOOST_CHECK_EQUAL(0, res[1]);
  BOOST_CHECK_EQUAL(0, res[2]);
  BOOST_CHECK_EQUAL(1, res[3]);
  BOOST_CHECK_EQUAL(1, res[4]);
}

BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> queries {{0, 1, 0}, {2, 2, 1}};
  std::string s("lyb");

  // act
  auto res = solution.canMakePaliQueries(s, queries);

  // assert
  BOOST_CHECK_EQUAL(0, res[0]);
  BOOST_CHECK_EQUAL(1, res[1]);
}

BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> queries{
      {1, 1, 1}, {2, 3, 0}, {3, 3, 1}, {0, 3, 2}, {1, 3, 3},
      {2, 3, 1}, {3, 3, 1}, {0, 3, 0}, {1, 1, 1}, {2, 3, 0},
      {3, 3, 1}, {0, 3, 1}, {1, 1, 1}};
  std::string s("hunu");

  // act
  auto res = solution.canMakePaliQueries(s, queries);
  BOOST_CHECK_EQUAL(1, res[0]);
  BOOST_CHECK_EQUAL(0, res[1]);
  BOOST_CHECK_EQUAL(1, res[2]);
  BOOST_CHECK_EQUAL(1, res[3]);
  BOOST_CHECK_EQUAL(1, res[4]);
  BOOST_CHECK_EQUAL(1, res[5]);
  BOOST_CHECK_EQUAL(1, res[6]);
  BOOST_CHECK_EQUAL(0, res[7]);
  BOOST_CHECK_EQUAL(1, res[8]);
  BOOST_CHECK_EQUAL(0, res[9]);
  BOOST_CHECK_EQUAL(1, res[10]);
  BOOST_CHECK_EQUAL(1, res[11]);
  BOOST_CHECK_EQUAL(1, res[12]);
}
