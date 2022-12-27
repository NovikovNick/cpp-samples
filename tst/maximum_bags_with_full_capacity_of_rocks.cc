#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximum_bags_with_full_capacity_of_rocks.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> capacity{10, 2, 2};
  std::vector<int> rocks{2, 2, 0};
  int additionalRocks = 100;

  // act
  auto res = solution.maximumBags(capacity, rocks, additionalRocks);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1
