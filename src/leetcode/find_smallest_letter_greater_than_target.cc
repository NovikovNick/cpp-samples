#ifndef LEETCODE_FIND_SMALLEST_LETTER_GREATER_THAN_TARGET_H
#define LEETCODE_FIND_SMALLEST_LETTER_GREATER_THAN_TARGET_H
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
  char nextGreatestLetter(vector<char>& letters, char target) {
    const auto it = std::upper_bound(letters.begin(), letters.end(), target);
    return it == letters.end() ? letters[0] : *it;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_SMALLEST_LETTER_GREATER_THAN_TARGET_H
