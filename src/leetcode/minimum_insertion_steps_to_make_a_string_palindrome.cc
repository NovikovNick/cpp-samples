#ifndef LEETCODE_MINIMUM_INSERTION_STEPS_TO_MAKE_A_STRING_PALINDROME_H
#define LEETCODE_MINIMUM_INSERTION_STEPS_TO_MAKE_A_STRING_PALINDROME_H
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
  int minInsertions(string s) {
    debug("{}\n", s);

    std::vector<int> dp(s.size());
    for (int i = 0; i < s.size(); ++i) {
      dp[i] = s[i] == s[s.size() - 1 - i];
    }

    for (const auto it : dp) debug("{}", it);
    debug("\n");

    std::vector<int> counts(128);
    for (const auto ch : s) ++counts[ch];

    print(counts);


    for (int i = s.size() - 1; i >= 0; --i) {
      --counts[s[i]];
      debug("-------- {} -------\n", i);
      print(counts);
    }
    return 42;
  }

  void print(std::vector<int>& counts) {
    for (int i = 0; i < counts.size(); ++i) {
      if (counts[i] != 0) debug("{}: {}\n", static_cast<char>(i), counts[i]);
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_INSERTION_STEPS_TO_MAKE_A_STRING_PALINDROME_H
