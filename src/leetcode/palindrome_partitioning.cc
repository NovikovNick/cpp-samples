#ifndef LEETCODE_PALINDROME_PARTITIONING_H
#define LEETCODE_PALINDROME_PARTITIONING_H
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
  using PALINDROMES = std::vector<std::string>;
  using PARTITION = std::vector<PALINDROMES>;

 public:
  PARTITION partition(string s) {
    PALINDROMES palindromes;
    PARTITION res;
    backtrack(0, 1, s, palindromes, res);
    return res;
  }

  void backtrack(const int begin, int count, const std::string& s,
                 PALINDROMES& palindromes, PARTITION& res) {
    int n = s.size();

    if (begin == n) {
      res.emplace_back(palindromes.begin(), palindromes.end());
      return;
    }

    while ((begin + count) <= n) {
      if (isPalindrome(begin, count, s)) {
        palindromes.push_back(s.substr(begin, count));
        backtrack(begin + count, 1, s, palindromes, res);
        palindromes.pop_back();
      }
      ++count;
    }
  }

  bool isPalindrome(const int begin, const int count, const std::string& s) {
    for (int left = begin, right = begin + count - 1; left < right; ++left, --right)
      if (s[left] != s[right]) return false;
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PALINDROME_PARTITIONING_H
