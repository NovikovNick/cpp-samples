#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/find-median-from-data-stream.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::MedianFinder solution;
  

  // act
  solution.addNum(1);
  solution.addNum(2);
  auto r1 = solution.findMedian();
  solution.addNum(3);
  auto r2 = solution.findMedian();

  // assert
  BOOST_CHECK_EQUAL(1.5, r1);
  BOOST_CHECK_EQUAL(2.0, r2);
}
