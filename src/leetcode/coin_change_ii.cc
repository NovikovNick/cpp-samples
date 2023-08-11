#ifndef LEETCODE_COIN_CHANGE_II_H
#define LEETCODE_COIN_CHANGE_II_H
#include <algorithm>
#include <format>
#include <iostream>
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
  int combination_count;
  std::vector<int> curr;

 public:
  Solution() : combination_count(0), curr({}){};

  int change(int amount, vector<int>& coins) {
    backtrack(0, 0, amount, coins);
    return combination_count;
  }

  void backtrack(int i, int sum, const int amount, const std::vector<int>& coins) {
    if (sum >= amount) {
      if (sum == amount) {
        ++combination_count;
        for (const auto it : curr) debug("{} ", it);
        debug(" == {} \n", sum);
      }
      return;
    }

    for (; i < coins.size(); ++i) {
      curr.push_back(coins[i]);
      sum += coins[i];
      backtrack(i, sum, amount, coins);
      sum -= coins[i];
      curr.pop_back();
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COIN_CHANGE_II_H
