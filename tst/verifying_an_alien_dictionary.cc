#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/verifying_an_alien_dictionary.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words{"hello", "leetcode"};
  std::string order("hlabcdefgijkmnopqrstuvwxyz");

  // act
  auto res = solution.isAlienSorted(words, order);

  // assert
  BOOST_CHECK(res);
}
#endif  // !CASE_1
