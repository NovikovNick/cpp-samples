#ifndef LEETCODE_FIRST_UNIQUE_CHARACTER_IN_A_STRING_H
#define LEETCODE_FIRST_UNIQUE_CHARACTER_IN_A_STRING_H
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
  int firstUniqChar(string s) {
    int n = s.size();
    std::vector<int> hash(26, 0);
    for (int i = 0; i < n; ++i) ++hash[s[i] - 'a'];
    for (int i = 0; i < n; ++i) if(hash[s[i] - 'a'] == 1) return i;
    return -1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIRST_UNIQUE_CHARACTER_IN_A_STRING_H
