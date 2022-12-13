#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/minimum_falling_path_sum.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> matrix{
	  {2, 1, 3}, 
	  {6, 5, 4}, 
	  {7, 8, 9}
  };
  // act
  auto res = solution.minFallingPathSum(matrix);

  // assert
  BOOST_CHECK_EQUAL(13, res);
}
#endif  // !CASE_1
