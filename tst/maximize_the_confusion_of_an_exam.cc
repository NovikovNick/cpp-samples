#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/maximize_the_confusion_of_an_exam.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::string answerKey = "TTFTTFTT";
  int k = 1;

  // act
  auto res = solution.maxConsecutiveAnswers(answerKey, k);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_1
