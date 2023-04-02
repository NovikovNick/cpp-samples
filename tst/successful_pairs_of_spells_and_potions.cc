#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/successful_pairs_of_spells_and_potions.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<int> spells{5, 1, 3};
  std::vector<int> potions{1, 2, 3, 4, 5};
  int k = 7;

  // act
  auto res = solution.successfulPairs(spells, potions, k);

  // assert 4,0,3
  BOOST_CHECK_EQUAL(4, res[0]);
  BOOST_CHECK_EQUAL(0, res[1]);
  BOOST_CHECK_EQUAL(3, res[2]);
}
#endif  // !CASE_1
