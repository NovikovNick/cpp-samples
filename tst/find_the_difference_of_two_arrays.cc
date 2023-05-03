#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_the_difference_of_two_arrays.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  // std::vector<int> nums1{1, 2, 3}, nums2{2, 4, 6};
  std::vector<int> nums1{1, 1, 2, 2}, nums2{1, 2, 3, 3};
  // act
  auto res = solution.findDifference(nums1, nums2);

  // assert
  for (const auto it : res[0]) debug("{}, ", it);
  debug("\n");
  for (const auto it : res[1]) debug("{}, ", it);
  debug("\n");

  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
