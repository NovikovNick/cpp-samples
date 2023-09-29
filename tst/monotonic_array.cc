#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/monotonic_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 2, 3, 4};

  // act
  auto res = solution.isMonotonic(nums);

  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
