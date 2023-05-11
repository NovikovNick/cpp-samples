#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/uncrossed_lines.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1{2,  5,  1, 2, 5, 45, 6,  7, 89, 1,  3,
                         45, 6,  7, 8, 9, 10, 23, 4, 5,  67, 8,
                         9,  12, 3, 4, 5, 6,  7,  8, 9,  10};
  std::vector<int> nums2{10, 5,  2, 1, 5, 2, 1,  4, 6,  8, 3, 6,
                         7,  8,  9, 2, 4, 5, 7,  9, 12, 4, 5, 63,
                         56, 77, 7, 8, 9, 1, 23, 4, 4,  4};

  // act
  auto res = solution.maxUncrossedLines(nums1, nums2);

  // assert
  BOOST_CHECK_EQUAL(18, res);
}
#endif  // !CASE_1
