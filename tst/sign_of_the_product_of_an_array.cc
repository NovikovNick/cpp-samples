#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/sign_of_the_product_of_an_array.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> nums{-1, -2, -3, -4, 3, 2, 1};

  // act
  auto res = solution.arraySign(nums);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_1
