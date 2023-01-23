#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/find_the_town_judge.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> trust{{1,2}};
  // act
  auto res = solution.findJudge(2, trust);

  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1
