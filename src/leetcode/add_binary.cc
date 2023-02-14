#ifndef LEETCODE_ADD_BINARY_H
#define LEETCODE_ADD_BINARY_H
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
//

class Solution {
 public:
  string addBinary(string a, string b) {
    if (a.size() < b.size()) return addBinary(b, a);
    uint8_t lhs, rhs, res, carry = 0;
    for (int i = 0; i < a.size(); ++i) {
      lhs = a[a.size() - 1 - i] == '1';
      rhs = i < b.size() ? b[b.size() - 1 - i] == '1' : 0;
      res = lhs + rhs + carry;
      carry = res >> 1;  // i.e. res / 2
      debug("{} ? {} = {}({})\n", lhs, rhs, res, carry);
      a[a.size() - 1 - i] = res % 2 + '0';
    }
    return carry ? "1" + a : a;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ADD_BINARY_H
