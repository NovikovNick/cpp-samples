#ifndef LEETCODE_OPTIMAL_PARTITION_OF_STRING_H
#define LEETCODE_OPTIMAL_PARTITION_OF_STRING_H
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
 public:
  int partitionString(string s) {
    /*std::vector<int> counts(26);
    int res = 1;
    for (const auto it : s) {
      if (++counts[it - 'a'] > 1) {
        std::fill(counts.begin(), counts.end(), 0);
        ++counts[it - 'a'];
        ++res;
      }
    }
    return res;*/

    auto reducer = [counts = std::vector<int>(26)](auto res, auto it) mutable {
      if (++counts[it - 'a'] > 1) {
        std::fill(counts.begin(), counts.end(), 0);
        ++counts[it - 'a'];
        ++res;
      }
      return res;
    };
    return std::accumulate(s.cbegin(), s.cend(), 1, reducer);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_OPTIMAL_PARTITION_OF_STRING_H
