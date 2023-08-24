#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/text_justification.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> words;
  // act
  auto res = solution.fullJustify(words, 0);

  // assert
  //BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
