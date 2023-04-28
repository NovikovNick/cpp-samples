#ifndef LEETCODE_SIMILAR_STRING_GROUPS_H
#define LEETCODE_SIMILAR_STRING_GROUPS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class UF {
  std::vector<int> parents_;

 public:
  int group_count;

  UF(const int n) : parents_(std::vector<int>(n)), group_count(n) {
    std::iota(parents_.begin(), parents_.end(), 0);
  };

  void join(const int a, const int b) {
    const int parent_a = find(a);
    const int parent_b = find(b);
    if (parent_a != parent_b) {
      parents_[parent_b] = parents_[b] = parent_a;
      --group_count;
    }
  };

  int find(int i) {
    if (i != parents_[i]) parents_[i] = find(parents_[i]);
    return parents_[i];
  };
};
class Solution {
 public:
  int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    UF uf(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (isSimilar(strs[i], strs[j])) uf.join(i, j);
      }
    }
    return uf.group_count;
  }

  bool isSimilar(const std::string& lhs, const std::string& rhs) {
    int mismatch_count = 0;
    for (int i = 0; i < lhs.size(); ++i) {
      if (lhs[i] != rhs[i] && ++mismatch_count > 2) return false;
    }
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SIMILAR_STRING_GROUPS_H
