#ifndef LEETCODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#define LEETCODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
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
  std::vector<std::string> letters{
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

 public:
  vector<string> letterCombinations(string digits) {
    std::vector<std::string> res;
    std::string curr;
    if (!digits.empty()) backtracking(0, curr, digits, res);
    return res;
  }

  void backtracking(int i,
                    std::string& curr,
                    const std::string& digits,
                    std::vector<std::string>& res) {
    if (i == digits.size()) {
      res.push_back(curr);
      return;
    }

    for (const auto letter : letters[digits[i] - 48]) {
      curr.push_back(letter);
      backtracking(i + 1, curr, digits, res);
      curr.pop_back();
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
