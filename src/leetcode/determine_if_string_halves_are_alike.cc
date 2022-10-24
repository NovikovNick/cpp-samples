#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_DETERMINE_IF_STRING_HALVES_ARE_ALIKE_H
#define LEETCODE_DETERMINE_IF_STRING_HALVES_ARE_ALIKE_H

namespace leetcode {

using namespace std;

class Solution {
 public:
  bool halvesAreAlike(string s) {
    auto lenght = s.size();
    auto isVowel = [](const char &ch) -> bool {
      std::vector<char> chars{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
      return std::find(chars.cbegin(), chars.cend(), ch) != chars.end();
    };
    auto a = std::count_if(s.cbegin(), s.cbegin() + lenght / 2, isVowel);
    auto b = std::count_if(s.cbegin() + lenght / 2, s.cend(), isVowel);
    return a == b;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DETERMINE_IF_STRING_HALVES_ARE_ALIKE_H
