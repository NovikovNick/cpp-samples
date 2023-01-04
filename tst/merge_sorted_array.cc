#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 0
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/merge_sorted_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>


#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1{1, 0, 0, 0};
  std::vector<int> nums2{2, 5, 6};
  std::vector<int> expected{1, 2, 5, 6};

  // act
  solution.merge(nums1, 1, nums2, 3);

  // assert
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(expected[i], nums1[i]);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1{1, 2, 3, 0, 0, 0};
  std::vector<int> nums2{2, 5, 6};
  std::vector<int> expected{1, 2, 2, 3, 5, 6};

  // act
  solution.merge(nums1, 3, nums2, 3);

  // assert
  for (int i = 0; i < expected.size(); ++i)
    BOOST_CHECK_EQUAL(expected[i], nums1[i]);
}
#endif  // !CASE_2
