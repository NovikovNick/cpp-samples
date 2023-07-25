#ifndef LEETCODE_PEAK_INDEX_IN_A_MOUNTAIN_ARRAY_H
#define LEETCODE_PEAK_INDEX_IN_A_MOUNTAIN_ARRAY_H
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
  // O(log(n)) solution
  int peakIndexInMountainArray(vector<int>& arr) {
    int low = 0, mid, high = arr.size() - 1;
    while (low < high) {
      mid = (high + low) / 2;
      if (arr[mid] < arr[mid + 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }

  // O(n) solution
  /*int peakIndexInMountainArray(vector<int>& arr) {
    int max_index = 0;
    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] > arr[max_index]) max_index = i;
    }
    return max_index;
  }*/
};
}  // namespace leetcode
#endif  // LEETCODE_PEAK_INDEX_IN_A_MOUNTAIN_ARRAY_H
