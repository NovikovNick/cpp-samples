#define BOOST_TEST_MODULE SolutionTest
#define CASE_3 1
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/where_will_the_ball_fall.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid{{1, 1, 1, -1, -1},
                                     {1, 1, 1, -1, -1},
                                     {-1, -1, -1, 1, 1},
                                     {1, 1, 1, 1, -1},
                                     {-1, -1, -1, -1, -1}};

  // act
  auto res = solution.findBall(grid);

  // assert
  BOOST_CHECK_EQUAL(1, res[0]);
  BOOST_CHECK_EQUAL(-1, res[1]);
  BOOST_CHECK_EQUAL(-1, res[2]);
  BOOST_CHECK_EQUAL(-1, res[3]);
  BOOST_CHECK_EQUAL(-1, res[4]);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid{{-1}};

  // act
  auto res = solution.findBall(grid);

  // assert
  BOOST_CHECK_EQUAL(-1, res[0]);
}
#endif  // !CASE_1


#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> grid{{1, 1, 1, 1, 1, 1},
                                     {-1, -1, -1, -1, -1, -1},
                                     {1, 1, 1, 1, 1, 1},
                                     {-1, -1, -1, -1, -1, -1}};

  // act
  auto res = solution.findBall(grid);

  // assert
  BOOST_CHECK_EQUAL(0, res[0]);
  BOOST_CHECK_EQUAL(1, res[1]);
  BOOST_CHECK_EQUAL(2, res[2]);
  BOOST_CHECK_EQUAL(3, res[3]);
  BOOST_CHECK_EQUAL(4, res[4]);
  BOOST_CHECK_EQUAL(-1, res[5]);
}
#endif  // !CASE_1