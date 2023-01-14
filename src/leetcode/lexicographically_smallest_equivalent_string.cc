#ifndef LEETCODE_LEXICOGRAPHICALLY_SMALLEST_EQUIVALENT_STRING_H
#define LEETCODE_LEXICOGRAPHICALLY_SMALLEST_EQUIVALENT_STRING_H
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
class UnionFind {
  using NUM = uint8_t;
  std::vector<NUM> parents_;

 public:
  UnionFind() : parents_(std::vector<NUM>(26)) {
    std::iota(parents_.begin(), parents_.end(), 0);
  }
  void merge(const char lhs, const char rhs) {
    auto lgroup = find(lhs);
    auto rgroup = find(rhs);
    if (lgroup < rgroup) {
      parents_[rgroup] = lgroup;
    } else {
      parents_[lgroup] = rgroup;
    }
  }

  NUM find(const char ch) {
    NUM i = ch - 'a';
    while (i != parents_[i]) i = parents_[i];
    return i;
  }
};
class Solution {
 public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    UnionFind uf;
    for (int i = 0, sz = s1.size(); i < sz; ++i) uf.merge(s1[i], s2[i]);
    for (auto& it : baseStr) it = static_cast<char>(uf.find(it) + 'a');
    return baseStr;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LEXICOGRAPHICALLY_SMALLEST_EQUIVALENT_STRING_H
