#ifndef LEETCODE_BULB_SWITCHER_H
#define LEETCODE_BULB_SWITCHER_H
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
  int bulbSwitchBruteforce(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      bool switched = false;
      for (int j = 1; j <= i; ++j) {
        if (i % j == 0) switched = !switched;
      }
      res += switched;
    }
    return res;
  }

  int bulbSwitch(int n) {
    return sqrt(n);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BULB_SWITCHER_H
