#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define CASE_2 1
#define DEBUG 1

#include "../src/leetcode/naming_a_company.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> names{"coffee", "donuts", "time", "toffee"};
  // act
  auto res = solution.distinctNames(names);

  // assert
  BOOST_CHECK_EQUAL(solution.distinctNamesTries(names), res);
}
#endif  // !CASE_1


#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::string> names{"a", "c", "back"};
  
  // act
  auto res = solution.distinctNames(names);

  // assert
  BOOST_CHECK_EQUAL(solution.distinctNamesTries(names), res);
}
#endif  // !CASE_2
