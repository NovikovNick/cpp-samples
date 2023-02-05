#ifndef LEETCODE_FIND_ALL_ANAGRAMS_IN_A_STRING_H
#define LEETCODE_FIND_ALL_ANAGRAMS_IN_A_STRING_H
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
  vector<int> findAnagrams(string s, string p) {
    std::vector<int> res;
    if (s.size() < p.size()) return res;

    std::vector<int> s_counts(26), p_counts(26);
    for (int i = 0; i < p.size(); ++i) {
      ++p_counts[p[i] - 'a'];
      if (i != p.size() - 1) ++s_counts[s[i] - 'a'];
    }

    for (int begin = 0, end = p.size() - 1; end < s.size(); ++begin, ++end) {
      ++s_counts[s[end] - 'a'];
      if (p_counts == s_counts) res.push_back(begin);
      --s_counts[s[begin] - 'a'];
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_ALL_ANAGRAMS_IN_A_STRING_H
