#ifndef LEETCODE__H
#define LEETCODE__H
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
  int minCostConnectPoints(std::vector<std::vector<int>>& points) {
    for (auto& point : points) {
      debug("[{}, {}]\n", point[0], point[1]);
    }
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE__H
