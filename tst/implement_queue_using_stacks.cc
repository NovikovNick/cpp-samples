#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/implement_queue_using_stacks.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::MyQueue myQueue;
  std::vector<int> res(5);
  
  // act
  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);
  myQueue.push(4);
  res[0] = myQueue.pop();
  myQueue.push(5);

  res[1] = myQueue.pop();
  res[2] = myQueue.pop();
  res[3] = myQueue.pop();
  res[4] = myQueue.pop();

  // assert
  BOOST_CHECK_EQUAL(1, res[0]);
  BOOST_CHECK_EQUAL(2, res[1]);
  BOOST_CHECK_EQUAL(3, res[2]);
  BOOST_CHECK_EQUAL(4, res[3]);
  BOOST_CHECK_EQUAL(5, res[4]);
}
#endif  // !CASE_1
