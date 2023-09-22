#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/design_hashmap.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::MyHashMap hashmap;
  hashmap.remove(1);
  // act
  // auto res = solution.test(1);

  // assert
  // BOOST_CHECK_EQUAL(42, res);
}
#endif  // !CASE_1
