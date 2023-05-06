#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/number_of_subsequences_that_satisfy_the_given_sum_condition.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector nums{3, 5, 6, 7};
  int target = 9;

  // act
  auto res = solution.numSubseq(nums, target);

  // assert
  BOOST_CHECK_EQUAL(4, res);
}
#endif  // !CASE_1
