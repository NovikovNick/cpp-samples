#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/binary_search.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 2, 3};

  // act
  auto res = solution.search(nums, 44);

  // assert
  BOOST_CHECK_EQUAL(0, res);
}
#endif  // !CASE_1
