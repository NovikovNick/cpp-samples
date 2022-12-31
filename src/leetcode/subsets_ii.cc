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

  struct hash {
    size_t operator()(const SET& nums) const {
      size_t res = 0;
      for (const auto& it : nums) res = res ^ std::hash<int>{}(it);
      return res;
    }
  };

  struct equals {
    bool operator()(const SET& a, const SET& b) const {
      std::vector<int> aTable(20), bTable(20);
      for (const auto& it : a) ++aTable[it + 9];
      for (const auto& it : b) ++bTable[it + 9];
      return aTable == bTable;
    }
  };

  using HASHSET = std::unordered_set<SET, hash, equals>;

 public:
  vector<SET> subsetsWithDup(SET& nums) {
    HASHSET set;
    dfs(0, {}, set, nums);

    std::vector<SET> res(set.begin(), set.end());
    return res;
  }

  void dfs(int i, SET set, HASHSET& res, const SET& nums) {
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
