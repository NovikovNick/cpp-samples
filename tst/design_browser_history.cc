#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/design_browser_history.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::BrowserHistory browser("homepage");
  browser.visit("page1");
  browser.visit("page2");
  browser.visit("page3");
  browser.visit("page4");
  browser.visit("page5");
  browser.visit("page6");

  // act
  std::string res;
  res = browser.back(1);
  res = browser.back(1);
  res = browser.back(1);
  res = browser.back(1);
  res = browser.back(1);
  res = browser.forward(1);
  browser.visit("page7");

  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
