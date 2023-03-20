#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/can_place_flowers.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> flowerbed{1, 0, 0, 0, 1};
  int n = 1;

  // act
  auto res = solution.canPlaceFlowers(flowerbed, n);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
