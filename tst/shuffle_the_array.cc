#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/shuffle_the_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 2, 3, 4, 5, 6};

  // act
  auto res = solution.shuffle(nums, 3);

  // assert
  for (const auto& it : res) debug("{} ", it);
  debug("\n");
}
#endif  // !CASE_1
