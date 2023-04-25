#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/smallest_number_in_infinite_set.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::SmallestInfiniteSet solution;

  // act & assert
  solution.addBack(2);
  BOOST_CHECK_EQUAL(1, solution.popSmallest());
  BOOST_CHECK_EQUAL(2, solution.popSmallest());
  BOOST_CHECK_EQUAL(3, solution.popSmallest());
  solution.addBack(1);
  BOOST_CHECK_EQUAL(1, solution.popSmallest());
  BOOST_CHECK_EQUAL(4, solution.popSmallest());
  BOOST_CHECK_EQUAL(5, solution.popSmallest());
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::SmallestInfiniteSet solution;

  // act & assert
  BOOST_CHECK_EQUAL(1, solution.popSmallest());
  BOOST_CHECK_EQUAL(2, solution.popSmallest());
  BOOST_CHECK_EQUAL(3, solution.popSmallest());
  solution.addBack(2);
  solution.addBack(2);
  solution.addBack(1);
  BOOST_CHECK_EQUAL(1, solution.popSmallest());
  BOOST_CHECK_EQUAL(2, solution.popSmallest());
  BOOST_CHECK_EQUAL(4, solution.popSmallest());
  BOOST_CHECK_EQUAL(5, solution.popSmallest());
}
#endif  // !CASE_2