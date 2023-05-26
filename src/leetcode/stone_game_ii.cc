#ifndef LEETCODE_STONE_GAME_II_H
#define LEETCODE_STONE_GAME_II_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <numeric>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    std::vector<int> dp(n);

    int sum = 0;
    int move = 1;
    for (int i = 0; i < n; ++i) {
      sum = std::accumulate(piles.begin() + i, piles.begin() + i + 2 * move, sum);
      dp[i] = sum;
      move *= 2;
      i = 2 * move;
    }

    return *std::max_element(dp.begin(), dp.end());
  }
};
}  // namespace leetcode
#endif  // LEETCODE_STONE_GAME_II_H
