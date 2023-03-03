#ifndef LEETCODE_FIND_THE_INDEX_OF_THE_FIRST_OCCURRENCE_IN_A_STRING_H
#define LEETCODE_FIND_THE_INDEX_OF_THE_FIRST_OCCURRENCE_IN_A_STRING_H
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
  int strStr(string haystack, string needle) {
    return haystack.find(needle);
    /*
    int threshold = haystack.size() - needle.size() + 1;
    for (int i = 0; i < threshold; ++i) {
      if (equal(i, haystack, needle)) return i;
    }
    return -1;
    */
  }

  bool equal(const int begin, const std::string& haystack,
             const std::string& needle) {
    for (int i = 0; i < needle.size(); ++i) {
      if (haystack[begin + i] != needle[i]) return false;
    }
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_THE_INDEX_OF_THE_FIRST_OCCURRENCE_IN_A_STRING_H
