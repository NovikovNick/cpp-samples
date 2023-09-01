#ifndef LEETCODE_COUNTING_BITS_H
#define LEETCODE_COUNTING_BITS_H
#include <algorithm>
#include <bitset>
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

constexpr std::vector<int> init() {
  int n = 1e5 + 1;
  std::vector<int> res(n);
  for (uint32_t i = 0; i < n; ++i) {
    res[i] = std::bitset<32>(i).count();
  }
  return res;
}

class Solution {
 public:
  static const inline std::vector<int> bits = init();

  vector<int> countBits(int n) {
    return std::vector(bits.begin(), bits.begin() + n + 1);
  }
};

}  // namespace leetcode
#endif  // LEETCODE_COUNTING_BITS_H
