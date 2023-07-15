#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximum_number_of_events_that_can_be_attended_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> events;
  int k = 0;

  // act
  auto res = solution.maxValue(events, k);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
