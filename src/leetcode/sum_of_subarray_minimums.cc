#ifndef LEETCODE_SUM_OF_SUBARRAY_MINIMUMS_H
#define LEETCODE_SUM_OF_SUBARRAY_MINIMUMS_H
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

using It = std::vector<int>::const_iterator;
class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    It begin = arr.cbegin(), end = arr.cend();
    int sum = 0;
    while (begin < end) {
      sum = (sum + sumSubarrayMins(begin, end)) % 1000000007;
      ++begin;
      --end;
    }
    return sum;
  }

  int sumSubarrayMins(It begin, It end) {
    int sum = 0, min = 3 * 1000000;
    It curr = begin;
    while (curr != end) {
      if (begin != curr) {
        min = *std::min_element(begin, curr);
        sum += min;
      }
      min = *std::min_element(curr, end);
      sum += min;
      ++curr;
    }
    return sum;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SUM_OF_SUBARRAY_MINIMUMS_H
