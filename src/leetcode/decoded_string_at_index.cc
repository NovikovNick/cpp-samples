#ifndef LEETCODE_DECODED_STRING_AT_INDEX_H
#define LEETCODE_DECODED_STRING_AT_INDEX_H
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
  string decodeAtIndex(string s, int k) {
    /*auto str;
    for (int i = 0; str.size() < k; ++i) {
      str.append(s[i]);
    }
    return str[k];*/
    return "";
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DECODED_STRING_AT_INDEX_H
