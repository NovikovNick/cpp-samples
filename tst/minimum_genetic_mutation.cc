#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/minimum_genetic_mutation.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string startGene{"AACCGGTT"};
  std::string endGene{"AACCGGTA"};
  std::vector<std::string> bank{"AACCGGTA"};
  // act
  auto res = solution.minMutation(startGene, endGene, bank);
  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::string startGene{"AACCGGTT"};
  std::string endGene{"AAACGGTA"};
  std::vector<std::string> bank{"AACCGGTA", "AACCGCTA", "AAACGGTA"};
  // act
  auto res = solution.minMutation(startGene, endGene, bank);
  // assert
  BOOST_CHECK_EQUAL(2, res);
}
#endif  // !CASE_1