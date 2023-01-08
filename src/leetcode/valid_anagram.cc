#ifndef LEETCODE__H
#define LEETCODE__H
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
  bool isAnagram(std::string s, std::string t) {
    std::vector<int> s_hash(26, 0);
    std::vector<int> t_hash(26, 0);
    for (const auto& ch : s) ++s_hash[ch - 'a'];
    for (const auto& ch : t) ++t_hash[ch - 'a'];
    return s_hash == t_hash;
  }
};
}  // namespace leetcode
#endif  // LEETCODE__H
