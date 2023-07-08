#ifndef LEETCODE_PUT_MARBLES_IN_BAGS_H
#define LEETCODE_PUT_MARBLES_IN_BAGS_H
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
  long long putMarbles(vector<int>& weights, int k) {
    for (const auto weight : weights) debug("{} ", weight);
    debug("\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PUT_MARBLES_IN_BAGS_H
