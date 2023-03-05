#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define CASE_3 1
#define DEBUG 1

#include "../src/leetcode/jump_game_iv.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> arr{100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
  // act
  auto res = solution.minJumps(arr);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> arr(5e4, 7);
  arr[arr.size() - 1] = 11;

  // act
  auto res = solution.minJumps(arr);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> arr(5e4, 7);
  arr[0] = 11;

  // act
  auto res = solution.minJumps(arr);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1