#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_k_pairs_with_smallest_sums.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums1{1, 1, 2};
  std::vector<int> nums2{1, 2, 3};
  int k = 10;
  std::vector<std::vector<int>> expected{{1, 2}, {1, 4}, {1, 6}};

  // act
  auto res = solution.kSmallestPairs(nums1, nums2, k);

  // assert
  int n = std::min<int>(k, nums1.size() * nums2.size());
  for (int i = 0; i < n; ++i) {
    //BOOST_CHECK_EQUAL(expected[i][0], res[i][0]);
    //BOOST_CHECK_EQUAL(expected[i][1], res[i][1]);
    debug("{}, {}\n", res[i][0], res[i][1]);
  }
}
#endif  // !CASE_1
