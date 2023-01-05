#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/intersection_of_two_arrays_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1{1, 2, 2, 1};
  std::vector<int> nums2{2, 2};
  std::vector<int> expected{2, 2};

  // act
  auto res = solution.intersect(nums1, nums2);

  // assert
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(expected[i], res[i]);
}
#endif  // !CASE_1
