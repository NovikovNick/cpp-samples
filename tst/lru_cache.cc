#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/lru_cache.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::LRUCache solution(2);

  // act & assert
  solution.put(1, 1);
  solution.put(2, 2);
  BOOST_CHECK_EQUAL(1, solution.get(1));
  solution.put(3, 3);
  BOOST_CHECK_EQUAL(-1, solution.get(2));
  solution.put(4, 4);
  BOOST_CHECK_EQUAL(-1, solution.get(1));
  BOOST_CHECK_EQUAL(3, solution.get(3));
  BOOST_CHECK_EQUAL(4, solution.get(4));
}
#endif  // !CASE_1
