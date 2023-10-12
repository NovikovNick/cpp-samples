#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_in_mountain_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  leetcode::MountainArray mountainArr;
  int target = 3;

  // act
  auto res = solution.findInMountainArray(target, mountainArr);

  // assert
  BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
