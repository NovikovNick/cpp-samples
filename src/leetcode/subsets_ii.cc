#ifndef LEETCODE_SUBSETS_II_H
#define LEETCODE_SUBSETS_II_H
#include <algorithm>
#include <format>
#include <iostream>
#include <set>
#include <unordered_set>
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
  using SET = std::vector<int>;

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
  vector<SET> subsetsWithDup(SET& nums) {
    std::sort(nums.begin(), nums.end());
    std::set<SET> set;
    dfs(0, {}, set, nums);
    std::vector<SET> res(set.begin(), set.end());
    return res;
  }

  void dfs(int i, SET set, std::set<SET>& res, const SET& nums) {
    res.insert(set);
    for (; i < nums.size(); ++i) {
      SET set2 = set;
      set2.push_back(nums[i]);
      dfs(i + 1, set2, res, nums);
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SUBSETS_II_H
