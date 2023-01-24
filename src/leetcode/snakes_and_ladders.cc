#ifndef LEETCODE_SNAKES_AND_LADDERS_H
#define LEETCODE_SNAKES_AND_LADDERS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class Solution {
  using BOARD = std::vector<std::vector<int>>;

 public:
  int snakesAndLadders(BOARD& board) {
    int n = board.size();
    for (int i = 0; i < n * n; ++i) {
      debug("{:3d}", getInBoustrophedonOrder(board, i));
      if (i % n == n - 1) debug("\n");
    }
    // order
    std::vector<int> ordered(n * n);
    for (int i = 0; i < n * n; ++i)
      ordered[getInBoustrophedonOrder(board, i)] = board[i / n][i % n];
    debug("                  ");
    for (const auto& it : ordered) debug("{:3d}", it);
    debug("\n");

    // dp
    std::vector<int> dp(n * n + 6, 0);
    std::iota(dp.begin() + 7, dp.end(), 1);
    for (const auto& it : dp) debug("{:3d}", it);
    debug("\n");

    // count
    for (int i = 1; i < n * n; ++i) {
      int& curr = dp[i + 6];
      int steps = *std::min_element(dp.begin() + i, dp.begin() + i + 6) + 1;
      int snake = ordered[i];
      if (snake != -1) {
        if (dp[snake + 5] > steps) {
          dp[snake + 5] = steps;

        }
      }
      curr = std::min(curr, steps);
    }

    for (const auto& it : dp) debug("{:3d}", it);
    debug("\n");

    return dp[n * n + 5];
  }

  int getInBoustrophedonOrder(const BOARD& board, const int i) {
    int n = board.size();
    int row = i / n;
    int col = (n - 1) % 2 && (row % 2) ? i % n : n - i % n - 1;
    return n * (n - 1) - row * n + col;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SNAKES_AND_LADDERS_H
