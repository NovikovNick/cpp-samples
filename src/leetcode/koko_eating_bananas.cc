#ifndef LEETCODE_KOKO_EATING_BANANAS_H
#define LEETCODE_KOKO_EATING_BANANAS_H
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

// A regular everyday normal monkey
// who has a 114 155 (1e9 / 24 / 365) years to eat bananas...
class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, mid, high = 1e9;

    while (low <= high) {
      mid = low + ((high - low) >> 1);
      debug("{:10d}-{:10d}-{:10d}\n", low, mid, high);
      if (great(h, mid, piles)) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }

  int great(const int h, const double k, const std::vector<int>& piles) {
    uint64_t res = 0;
    for (const auto& pile : piles)
      if ((res += std::ceil(pile / k)) > h) return true;  // prevent overflow
    return res > h;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_KOKO_EATING_BANANAS_H
