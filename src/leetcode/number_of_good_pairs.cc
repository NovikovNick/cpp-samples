#ifndef LEETCODE_NUMBER_OF_GOOD_PAIRS_H
#define LEETCODE_NUMBER_OF_GOOD_PAIRS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <array>

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
  int numIdenticalPairs(vector<int>& nums) {
    std::array<int, 101> counts;
    std::fill(counts.begin(), counts.end(), 0);
    for (auto num : nums) ++counts[num];

    int res = 0;
    for (auto count : counts) {
      if (count > 1) res += calculatePairs(count);
    }
    return res;
  }

  int calculatePairs(int count) {
    if (count == 2) return 1;
    return calculatePairs(count - 1) + count - 1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_GOOD_PAIRS_H
