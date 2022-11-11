#ifndef LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
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
  int removeDuplicates(vector<int>& nums) {
    int k = 1;
    for (int fst = nums[0], i = 1, size = nums.size(); i < size; ++i)
      if (fst != nums[i]) fst = nums[k++] = nums[i];
    return k;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
