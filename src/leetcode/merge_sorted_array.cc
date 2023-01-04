#ifndef LEETCODE_MERGE_SORTED_ARRAY_H
#define LEETCODE_MERGE_SORTED_ARRAY_H
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
  // O(n log(n) )
  /*void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    std::copy(nums2.begin(), nums2.end(), nums1.begin() + m);
    std::sort(nums1.begin(), nums2.end());
  }*/

  // O(n)
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (m == 0) {
      std::copy(nums2.begin(), nums2.end(), nums1.begin());
      return;
    }
    if (n == 0) return;

    std::rotate(nums1.begin(), nums1.begin() + m, nums1.end());

    auto it = nums1.begin();
    auto it1 = nums1.begin() + n;
    auto it2 = nums2.begin();

    while (it != nums1.end()) {
      print(nums1);
      if (it1 == nums1.end()) {
        *it = *it2;
        ++it2;
      } else if (it2 == nums2.end()) {
        *it = *it1;
        ++it1;
      } else if (*it1 > *it2) {
        *it = *it2;
        ++it2;
      } else {
        *it = *it1;
        ++it1;
      }
      ++it;
    }
  }

  void print(std::vector<int>& nums) {
    for (const auto& num : nums) debug("{} ", num);
    debug("\n");
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MERGE_SORTED_ARRAY_H
