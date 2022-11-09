#define BOOST_TEST_MODULE SolutionTest
#define CASE_2 1
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/online_stock_span.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::StockSpanner spanner;
  std::vector<int> res(7, 0);
  // act
  res[0] = spanner.next(100);
  res[1] = spanner.next(80);
  res[2] = spanner.next(60);
  res[3] = spanner.next(70);
  res[4] = spanner.next(60);
  res[5] = spanner.next(75);
  res[6] = spanner.next(85);

  // act & assert
  BOOST_CHECK_EQUAL(1, res[0]);
  BOOST_CHECK_EQUAL(1, res[1]);
  BOOST_CHECK_EQUAL(1, res[2]);
  BOOST_CHECK_EQUAL(2, res[3]);
  BOOST_CHECK_EQUAL(1, res[4]);
  BOOST_CHECK_EQUAL(4, res[5]);
  BOOST_CHECK_EQUAL(6, res[6]);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::StockSpanner spanner;
  std::vector<int> res(7, 0);
  // act
  res[0] = spanner.next(29);
  res[1] = spanner.next(91);
  res[2] = spanner.next(62);
  res[3] = spanner.next(76);
  res[4] = spanner.next(51);

  // act & assert
  BOOST_CHECK_EQUAL(1, res[0]);
  BOOST_CHECK_EQUAL(2, res[1]);
  BOOST_CHECK_EQUAL(1, res[2]);
  BOOST_CHECK_EQUAL(2, res[3]);
  BOOST_CHECK_EQUAL(1, res[4]);
}
#endif  // !CASE_2
