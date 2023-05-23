#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/kth_largest_element_in_a_stream.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  int k = 3;
  std::vector<int> nums{4, 5, 8, 2};
  leetcode::KthLargest solution(k, nums);

  // act & assert
  BOOST_CHECK_EQUAL(4, solution.add(3));
  BOOST_CHECK_EQUAL(5, solution.add(5));
  BOOST_CHECK_EQUAL(5, solution.add(10));
  BOOST_CHECK_EQUAL(8, solution.add(9));
  BOOST_CHECK_EQUAL(8, solution.add(4));
}
#endif  // !CASE_1
