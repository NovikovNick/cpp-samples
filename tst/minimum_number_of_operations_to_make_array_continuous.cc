#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_number_of_operations_to_make_array_continuous.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{4, 2, 5, 3};

  // act
  auto res = solution.minOperations(nums);

  // assert
  BOOST_CHECK_EQUAL(0, res);
}
#endif  // !CASE_1
