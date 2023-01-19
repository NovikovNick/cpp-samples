#ifndef LEETCODE_REVERSE_WORDS_IN_A_STRING_III_H
#define LEETCODE_REVERSE_WORDS_IN_A_STRING_III_H
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
  string reverseWords(string s) {
    for (auto it = s.begin(); it != s.end(); ++it) {
      if (*it == ' ') continue;
      auto word_end = it;
      while (word_end != s.end() && *word_end != ' ') ++word_end;
      std::reverse(it, word_end);
      if (word_end == s.end()) break;  // !
      it = word_end;
    }
    return s;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REVERSE_WORDS_IN_A_STRING_III_H
