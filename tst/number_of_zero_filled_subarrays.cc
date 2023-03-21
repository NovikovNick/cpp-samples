#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/number_of_zero_filled_subarrays.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{0, 0, 0, 2, 0, 0};
  // act
  auto res = solution.zeroFilledSubarray(nums);

  // assert
  BOOST_CHECK_EQUAL(9, res);
}
#endif  // !CASE_1
