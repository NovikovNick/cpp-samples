#ifndef LEETCODE_MAKE_THE_STRING_GREAT_H
#define LEETCODE_MAKE_THE_STRING_GREAT_H
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
  string makeGood(string s) {
    bool notGood = true;
    while (notGood) {
      if (s.size() <= 1) return s;

      auto fst = s.begin();
      auto snd = fst + 1;
      auto end = s.end();
      notGood = false;

      while (snd < end) {
        if (*fst != *snd &&
            (*fst == std::toupper(*snd) || *snd == std::toupper(*fst))) {
          std::rotate(fst, snd + 1, end);
          end = end - 2;
          notGood = true;
        } else {
          ++fst;
          ++snd;
        }
      }
      s.erase(end, s.end());
    }
    return s;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAKE_THE_STRING_GREAT_H
