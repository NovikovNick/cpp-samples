#ifndef LEETCODE_KTH_MISSING_POSITIVE_NUMBER_H
#define LEETCODE_KTH_MISSING_POSITIVE_NUMBER_H
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
  int findKthPositive(vector<int>& arr, int k) {
    int expected = 0;
    int i = 0;
    while (k != 0) {
      ++expected;
      if (i >= arr.size() || expected != arr[i]) {
        --k;
      } else {
        ++i;
      }
    }
    return expected;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_KTH_MISSING_POSITIVE_NUMBER_H
