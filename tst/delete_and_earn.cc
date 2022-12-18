#define BOOST_TEST_MODULE SolutionTest
#define CASE_3 1
#define CASE_2 0
#define CASE_1 0
#define DEBUG 1

#include "../src/leetcode/delete_and_earn.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 1, 1, 2, 3, 4};

  // act
  auto res = solution.deleteAndEarn(nums);

  // assert
  BOOST_CHECK_EQUAL(7, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{8, 7, 3, 8, 1, 4, 10, 10, 10, 2};
  // act
  auto res = solution.deleteAndEarn(nums);

  // assert
  BOOST_CHECK_EQUAL(52, res);
}
#endif  // !CASE_2

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{2, 2, 3, 3, 3, 4};
  // act
  auto res = solution.deleteAndEarn(nums);

  // assert
  BOOST_CHECK_EQUAL(9, res);
}
#endif  // !CASE_2