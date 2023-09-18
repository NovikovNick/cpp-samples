#define BOOST_TEST_MODULE SolutionTest
#define CASE_1 1
#define DEBUG 1

#include "../src/leetcode/the_k_weakest_rows_in_a_matrix.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  int k = 3;
  std::vector<std::vector<int>> matrix{{1, 1, 0, 0, 0},
                                       {1, 1, 1, 1, 0},
                                       {1, 0, 0, 0, 0},
                                       {1, 1, 0, 0, 0},
                                       {1, 1, 1, 1, 1}};

  // act
  auto res = solution.kWeakestRows(matrix, k);

  // assert
  std::copy(res.begin(),  //
            res.end(),    //
            std::ostream_iterator<int>(std::cout, ", "));
}
#endif  // !CASE_1
