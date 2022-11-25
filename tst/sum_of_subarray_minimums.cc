#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/sum_of_subarray_minimums.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> arr{11, 81, 94, 43, 3};

  // act
  auto res = solution.sumSubarrayMins(arr);

  // assert
  BOOST_CHECK_EQUAL(444, res);
}
#endif  // !CASE_1
