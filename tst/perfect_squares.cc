#define BOOST_TEST_MODULE SolutionTest
#define CASE_3 1
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/perfect_squares.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.numSquares(12);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.numSquares(13);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_2


#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.numSquares(9999);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_3