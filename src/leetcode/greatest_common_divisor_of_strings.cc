#ifndef LEETCODE_GREATEST_COMMON_DIVISOR_OF_STRINGS_H
#define LEETCODE_GREATEST_COMMON_DIVISOR_OF_STRINGS_H
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
  string gcdOfStrings(string str1, string str2) {
    if (str1.size() < str2.size()) std::swap(str2, str1);
    if (str1.size() == str2.size()) return str1 == str2 ? str1 : "";

    return str1.substr(0, str2.size()) == str2
               ? gcdOfStrings(str1.substr(str2.size()), str2)
               : "";
  }
};
}  // namespace leetcode
#endif  // LEETCODE_GREATEST_COMMON_DIVISOR_OF_STRINGS_H
