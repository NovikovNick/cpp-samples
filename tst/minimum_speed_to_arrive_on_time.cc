#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_speed_to_arrive_on_time.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> dist{1, 3, 2};
  double hour = 5.9;

  // act
  auto res = solution.minSpeedOnTime(dist, hour);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
