#ifndef LEETCODE_DETECT_CAPITAL_H
#define LEETCODE_DETECT_CAPITAL_H
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }

  bool detectCapitalUse(string word) {
    if (word.size() < 2) return true;

    if (isUpper(word[0]) && isUpper(word[1]))
      return std::all_of(word.begin() + 2, word.end(), isUpper);

    if (isLower(word[0]) && isLower(word[1]))
      return std::all_of(word.begin() + 2, word.end(), isLower);

    if (isUpper(word[0]) && isLower(word[1]))
      return std::all_of(word.begin() + 2, word.end(), isLower);

    if (isLower(word[0]) && isUpper(word[1])) return false;

    return true;
  }

  static bool isUpper(const char ch) { return ch >= 'A' && ch <= 'Z'; }
  static bool isLower(const char ch) { return !isUpper(ch); }
};
}  // namespace leetcode
#endif  // LEETCODE_DETECT_CAPITAL_H
