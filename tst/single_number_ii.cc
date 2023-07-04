#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/single_number_ii.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums { 2, 2, 3, 2 };

  // act
  auto res = solution.singleNumber(nums);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1
