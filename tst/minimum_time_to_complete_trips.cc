#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_time_to_complete_trips.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> time{3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16};
  int totalTrips = 3333;

  // act
  auto res = solution.minimumTime(time, totalTrips);

  // assert
  BOOST_CHECK_EQUAL(1920, res);
}
#endif  // !CASE_1
