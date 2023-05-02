#ifndef LEETCODE_SIGN_OF_THE_PRODUCT_OF_AN_ARRAY_H
#define LEETCODE_SIGN_OF_THE_PRODUCT_OF_AN_ARRAY_H
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
  int arraySign(vector<int>& nums) {
    int negative = 0;
    for (const auto it : nums) {
      if (it == 0) return 0;
      if (it < 0) ++negative;
    }
    return negative & 1 ? -1 : 1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SIGN_OF_THE_PRODUCT_OF_AN_ARRAY_H
