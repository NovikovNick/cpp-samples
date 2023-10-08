#ifndef LEETCODE_MAX_DOT_PRODUCT_OF_TWO_SUBSEQUENCES_H
#define LEETCODE_MAX_DOT_PRODUCT_OF_TWO_SUBSEQUENCES_H
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
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    debug("max dot product\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAX_DOT_PRODUCT_OF_TWO_SUBSEQUENCES_H
