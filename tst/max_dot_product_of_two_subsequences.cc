#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/max_dot_product_of_two_subsequences.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1 = {2, 1, -2, 5};
  std::vector<int> nums2 = {3, 0, -6};

  // act
  auto res = solution.maxDotProduct(nums1, nums2);

  // assert
  BOOST_CHECK_EQUAL(18, res);
}
#endif  // !CASE_1
