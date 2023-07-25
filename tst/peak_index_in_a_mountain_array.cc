#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/peak_index_in_a_mountain_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> arr{0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 5, 2};

  // act
  auto res = solution.peakIndexInMountainArray(arr);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_1
