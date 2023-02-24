#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimize_deviation_in_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{111, 112, 130};
  

  // act
  auto res = solution.minimumDeviation(nums);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
