#ifndef LEETCODE_FIND_THE_HIGHEST_ALTITUDE_H
#define LEETCODE_FIND_THE_HIGHEST_ALTITUDE_H
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
  int largestAltitude(vector<int>& gain) {
    int max = 0, altitude = 0;
    for (const auto diff : gain) {
      altitude += diff;
      max = std::max(max, altitude);
      debug("{}\n", max);
    }
    return max;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_THE_HIGHEST_ALTITUDE_H
