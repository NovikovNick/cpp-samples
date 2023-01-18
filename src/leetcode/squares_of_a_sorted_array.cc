#ifndef LEETCODE_SQUARES_OF_A_SORTED_ARRAY_H
#define LEETCODE_SQUARES_OF_A_SORTED_ARRAY_H
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
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    auto left = nums.begin();
    auto right = nums.end() - 1;
    while (left <= right) {
      auto l_square = *left * *left;
      auto r_square = *right * *right;

      if (l_square > r_square) {
        std::rotate(left, left + 1, right + 1);
        *right = l_square;
      } else {
        *right = r_square;
      }
      --right;
    }
    return nums;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SQUARES_OF_A_SORTED_ARRAY_H
