#ifndef LEETCODE_ADD_TO_ARRAY_FORM_OF_INTEGER_H
#define LEETCODE_ADD_TO_ARRAY_FORM_OF_INTEGER_H
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
  vector<int> addToArrayForm(vector<int>& num, int k) {
    int n = num.size();
    std::vector<int> res;
    int carry = 0;
    for (int i = 0; i < n || k != 0 || carry != 0; ++i, k /= 10) {
      int lhs = i < n ? num[n - 1 - i] : 0;
      int rhs = k % 10;

      int sum = lhs + rhs + carry;
      carry = sum / 10;
      res.push_back(sum % 10);
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ADD_TO_ARRAY_FORM_OF_INTEGER_H
