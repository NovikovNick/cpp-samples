#ifndef LEETCODE_MAXIMUM_NUMBER_OF_VOWELS_IN_A_SUBSTRING_OF_GIVEN_LENGTH_H
#define LEETCODE_MAXIMUM_NUMBER_OF_VOWELS_IN_A_SUBSTRING_OF_GIVEN_LENGTH_H
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
  int maxVowels(string s, int k) {
    int max_vowels = 0;
    int end = std::min<int>(s.size(), k);
    for (int i = 0; i < end; ++i) {
      if (isVowel(s[i])) ++max_vowels;
    }

    int count_vowels = max_vowels;
    for (int begin = 0; end < s.size() && max_vowels < k; ++begin, ++end) {
      if (isVowel(s[begin])) --count_vowels;
      if (isVowel(s[end])) ++count_vowels;
      max_vowels = std::max(max_vowels, count_vowels);
    }

    return max_vowels;
  }
  inline bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_NUMBER_OF_VOWELS_IN_A_SUBSTRING_OF_GIVEN_LENGTH_H
