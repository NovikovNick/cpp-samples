#ifndef LEETCODE_REVERSE_WORDS_IN_A_STRING_H
#define LEETCODE_REVERSE_WORDS_IN_A_STRING_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
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
    // debug("Trying to reverse string: \"{}\"\n", s);
    std::stack<std::string> stack;
    std::string word;
    for (const auto& ch : s) {
      if (ch == ' ') {
        if (!word.empty()) {
          stack.push(word);
          word = "";
        }
      } else {
        word += ch;
      }
    }
    if (!word.empty()) {
      stack.push(word);
    }
    std::string res = stack.top();
    stack.pop();
    while (!stack.empty()) {
      res += " " + stack.top();
      stack.pop();
    }
    // debug("Result: \"{}\"\n", res);
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REVERSE_WORDS_IN_A_STRING_H
