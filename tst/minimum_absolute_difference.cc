#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_absolute_difference.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 3, 6, 10, 15};
  // act
  auto res = solution.minimumAbsDifference(nums);

  // assert
  for (const auto pair : res) {
    debug("{} - {}\n", pair[0], pair[1]);
  }
}
#endif  // !CASE_1
