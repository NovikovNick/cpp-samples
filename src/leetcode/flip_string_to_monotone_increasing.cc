#ifndef LEETCODE_FLIP_STRING_TO_MONOTONE_INCREASING_H
#define LEETCODE_FLIP_STRING_TO_MONOTONE_INCREASING_H
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
  int minFlipsMonoIncr(string s) {
    int left = 0, right = 0, sum = 5;
    std::vector<int> left_arr, right_arr, sum_arr;

    for (const auto& ch : s) {
      if (ch == '0') {
        left_arr.push_back(left);
        right_arr.push_back(std::min(--right, right));
      } else {
        left_arr.push_back(std::max(++left, left));
        right_arr.push_back(right);
      }
      sum_arr.push_back(sum + left + right);
    }

    for (const auto& it : s) debug("  {}", it);
    debug("\n");
    for (const auto& it : left_arr) debug("{:3d}", it);
    debug("\n");
    for (const auto& it : right_arr) debug("{:3d}", it);
    debug("\n");
    for (const auto& it : sum_arr) debug("{:3d}", it);
    debug("\n");

    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FLIP_STRING_TO_MONOTONE_INCREASING_H
