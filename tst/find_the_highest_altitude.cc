#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_the_highest_altitude.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> gain{-4, -3, -2, -1, 4, 3, 2};

  // act
  auto res = solution.largestAltitude(gain);

  // assert
  BOOST_CHECK_EQUAL(0, res);
}
#endif  // !CASE_1
