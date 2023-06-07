#ifndef LEETCODE_MINIMUM_FLIPS_TO_MAKE_A_OR_B_EQUAL_TO_C_H
#define LEETCODE_MINIMUM_FLIPS_TO_MAKE_A_OR_B_EQUAL_TO_C_H
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

class Solution {
 public:
  int minFlips(int a, int b, int c) {
    std::bitset<32> aBitset(a), bBitset(b), cBitset(c);

    std::cout << aBitset << std::endl;
    std::cout << bBitset << std::endl;
    std::cout << cBitset << std::endl;

    int flipsCount = 0;

    for (int i = 0; i < 32; ++i) {
      if ((aBitset[i] || bBitset[i]) == cBitset[i]) continue;

      // 0 1 0
      if (!aBitset[i] && bBitset[i] && !cBitset[i]) {
        ++flipsCount;
        continue;
      }

      aBitset[i] = !aBitset[i];
      ++flipsCount;
      if ((aBitset[i] || bBitset[i]) == cBitset[i]) continue;

      bBitset[i] = !bBitset[i];
      ++flipsCount;

      debug("{:d} {:d} {:d}\n",
            static_cast<int>(aBitset[i]),
            static_cast<int>(bBitset[i]),
            static_cast<int>(cBitset[i]));
    }
    return flipsCount;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_FLIPS_TO_MAKE_A_OR_B_EQUAL_TO_C_H
