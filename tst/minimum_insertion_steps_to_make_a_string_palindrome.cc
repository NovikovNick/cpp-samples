#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_insertion_steps_to_make_a_string_palindrome.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  // auto res = solution.minInsertions("mbadm");

  auto res = solution.minInsertions("bbaac");


  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
