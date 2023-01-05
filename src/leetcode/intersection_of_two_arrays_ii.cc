#ifndef LEETCODE_INTERSECTION_OF_TWO_ARRAYS_II_H
#define LEETCODE_INTERSECTION_OF_TWO_ARRAYS_II_H
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
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    
    std::vector<int> res;
    auto fst = nums1.begin();
    auto snd = nums2.begin();
    while (fst != nums1.end() && snd != nums2.end()) {
      if (*fst > *snd) {
        ++snd;
      } else if (*snd > *fst) {
        ++fst;
      } else {
        res.push_back(*fst);
        ++fst;
        ++snd;
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_INTERSECTION_OF_TWO_ARRAYS_II_H
