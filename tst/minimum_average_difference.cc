#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_average_difference.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>


#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{2, 5, 3, 9, 5, 3};
  // act
  auto res = solution.minimumAverageDifference(nums);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{0, 3};
  // act
  auto res = solution.minimumAverageDifference(nums);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_2