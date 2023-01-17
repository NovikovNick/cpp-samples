#ifndef LEETCODE_BINARY_SEARCH_H
#define LEETCODE_BINARY_SEARCH_H
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }  
  int search(vector<int>& nums, int target) {
    int left = 0, mid, right = nums.size() - 1;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BINARY_SEARCH_H
