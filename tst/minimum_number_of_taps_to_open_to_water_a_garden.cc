#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_number_of_taps_to_open_to_water_a_garden.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int n = 5;
  std::vector<int> ranges{3, 4, 1, 1, 0, 0};

  // act
  auto res = solution.minTaps(n, ranges);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
