#define BOOST_TEST_MODULE SolutionTest
#define CASE_7 1
#define CASE_6 1
#define CASE_5 1
#define CASE_4 1
#define CASE_3 1
#define CASE_2 1
#define CASE_1 1
#define DEBUG 0

#include "../src/leetcode/most_stones_removed_with_same_row_or_column.cc"

#include <boost/test/included/unit_test.hpp>
#include <iostream>

#if CASE_1
BOOST_AUTO_TEST_CASE(case1) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> stones{{0, 0}, {0, 1}, {1, 0},
                                       {1, 2}, {2, 1}, {2, 2}};
  // act
  auto res = solution.removeStones(stones);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_1

#if CASE_2
BOOST_AUTO_TEST_CASE(case2) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> stones{{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};

  // act
  auto res = solution.removeStones(stones);

  // assert
  BOOST_CHECK_EQUAL(3, res);
}
#endif  // !CASE_2

#if CASE_3
BOOST_AUTO_TEST_CASE(case3) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> stones{{0, 0}};

  // act
  auto res = solution.removeStones(stones);

  // assert
  BOOST_CHECK_EQUAL(0, res);
}
#endif  // !CASE_3

#if CASE_4
BOOST_AUTO_TEST_CASE(case4) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> stones{{0, 1}, {1, 1}};

  // act
  auto res = solution.removeStones(stones);

  // assert
  BOOST_CHECK_EQUAL(1, res);
}
#endif  // !CASE_4

#if CASE_5
BOOST_AUTO_TEST_CASE(case5) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> stones{{0, 1}, {1, 2}, {1, 3},
                                       {3, 3}, {2, 3}, {0, 2}};

  // act
  auto res = solution.removeStones(stones);

  // assert
  BOOST_CHECK_EQUAL(5, res);
}
#endif  // !CASE_5

#if CASE_6
BOOST_AUTO_TEST_CASE(case6) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> stones{{5, 9}, {9, 0}, {0, 0}, {7, 0}, {4, 3},
                                       {8, 5}, {5, 8}, {1, 1}, {0, 6}, {7, 5},
                                       {1, 6}, {1, 9}, {9, 4}, {2, 8}, {1, 3},
                                       {4, 2}, {2, 5}, {4, 1}, {0, 2}, {6, 5}};

  // act
  auto res = solution.removeStones(stones);

  // assert
  BOOST_CHECK_EQUAL(19, res);
}
#endif  // !CASE_6

#if CASE_7
BOOST_AUTO_TEST_CASE(case7) {
  // arrange
  leetcode::Solution solution;
  std::vector<std::vector<int>> stones{
      {42, 6},  {45, 45}, {16, 29}, {80, 40}, {43, 3},  {39, 83}, {18, 19},
      {77, 80}, {65, 39}, {21, 6},  {80, 78}, {1, 11},  {80, 12}, {26, 70},
      {98, 9},  {54, 13}, {53, 40}, {85, 3},  {75, 32}, {20, 9},  {37, 85},
      {48, 14}, {31, 65}, {9, 57},  {58, 47}, {29, 92}, {58, 20}, {38, 38},
      {71, 12}, {27, 50}, {17, 62}, {89, 89}, {51, 32}, {10, 85}, {19, 45},
      {66, 88}, {31, 21}, {5, 34},  {33, 34}, {70, 7},  {93, 93}, {19, 23},
      {49, 10}, {12, 39}, {92, 35}, {82, 71}, {69, 47}, {60, 65}, {70, 82},
      {59, 36}, {76, 87}, {3, 71},  {98, 36}, {26, 24}, {97, 86}, {51, 16},
      {92, 10}, {39, 88}, {82, 77}, {30, 51}, {28, 68}, {75, 88}, {97, 13},
      {91, 22}, {30, 70}, {11, 10}, {77, 23}, {33, 54}, {43, 78}, {2, 85},
      {66, 18}, {41, 22}, {72, 74}, {98, 65}, {8, 51},  {47, 72}, {96, 60},
      {71, 8},  {10, 66}, {40, 67}, {12, 52}, {9, 91},  {35, 86}, {39, 3},
      {90, 64}, {83, 58}, {24, 90}, {54, 16}, {22, 83}, {58, 43}, {53, 49},
      {59, 34}, {22, 0},  {89, 30}, {28, 94}, {3, 22},  {53, 61}, {56, 46},
      {72, 51}, {7, 74},  {67, 93}, {56, 33}, {55, 59}, {20, 15}, {20, 68},
      {75, 70}, {78, 28}, {97, 76}, {4, 8},   {55, 33}, {62, 61}, {19, 37},
      {21, 89}, {68, 53}, {96, 66}, {18, 1},  {42, 15}, {4, 60},  {4, 90},
      {81, 61}, {2, 75},  {0, 50},  {41, 60}, {14, 38}, {45, 17}, {29, 3},
      {59, 2},  {40, 5},  {40, 90}, {28, 56}, {75, 39}, {99, 34}, {16, 73},
      {43, 67}, {14, 97}, {28, 90}, {70, 22}, {67, 66}, {85, 76}, {82, 1},
      {63, 33}, {4, 29},  {75, 47}, {11, 69}, {45, 46}, {59, 79}, {24, 91},
      {55, 55}, {91, 10}, {73, 94}, {36, 86}, {94, 5},  {1, 7},   {27, 18},
      {76, 3},  {54, 20}, {83, 36}, {69, 39}, {25, 80}, {47, 42}, {71, 36},
      {21, 16}, {88, 97}, {92, 76}, {99, 79}, {15, 54}, {70, 71}, {84, 24},
      {64, 19}, {72, 44}, {19, 36}, {68, 59}, {47, 60}, {19, 98}, {77, 93},
      {82, 18}, {31, 1},  {24, 85}, {80, 49}, {15, 56}, {84, 34}, {24, 48},
      {3, 75},  {87, 98}, {16, 59}, {48, 96}, {45, 29}, {50, 31}, {50, 35},
      {37, 66}, {47, 44}, {79, 27}, {65, 55}, {86, 76}, {10, 45}, {43, 9},
      {33, 46}, {15, 6},  {37, 61}, {3, 29},  {77, 62}, {12, 54}};

  // act
  auto res = solution.removeStones(stones);


  // assert
  BOOST_CHECK_EQUAL(196, res);
}
#endif  // !CASE_1