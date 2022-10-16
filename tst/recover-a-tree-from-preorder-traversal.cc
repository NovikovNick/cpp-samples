#define BOOST_TEST_MODULE SolutionTest

#include "../src/leetcode/recover-a-tree-from-preorder-traversal.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#include "../src/util/tree_printer.h"
#include "../src/util/tree_printer.cc"

BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;

  // act
  auto res = solution.recoverFromPreorder("1-2--3--4-5--6--7");

  // assert
  util::walkTreeAndPrint(res);
  delete res;
}

 BOOST_AUTO_TEST_CASE(case2) {
   // arrange
   leetcode::Solution solution;

   // act
   auto res = solution.recoverFromPreorder("1-2--3---4-5--6---7");

   // assert
   util::walkTreeAndPrint(res);
   delete res;
 }

 BOOST_AUTO_TEST_CASE(case3) {
   // arrange
   leetcode::Solution solution;

   // act
   auto res = solution.recoverFromPreorder("1-401--349---90--88");

   // assert
   util::walkTreeAndPrint(res);
   delete res;
 }

 BOOST_AUTO_TEST_CASE(case4) {
   // arrange
   leetcode::Solution solution;

   // act
   auto res = solution.recoverFromPreorder("10-7--6-8--7--6");

   // assert
   util::walkTreeAndPrint(res);
   delete res;
 }
