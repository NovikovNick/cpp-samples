#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/predict_the_winner.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{1, 5, 2};

  // act
  auto res = solution.PredictTheWinner(nums);

  // assert
  BOOST_CHECK(!res);
}
#endif  // !CASE_1
