#ifndef LEETCODE_RANSOM_NOTE_H
#define LEETCODE_RANSOM_NOTE_H
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
  bool canConstruct(string ransomNote, string magazine) {
    std::vector<int> ransom_note_hash(26, 0);
    std::vector<int> magazine_hash(26, 0);

    for (const auto& ch : ransomNote) ++ransom_note_hash[ch - 'a'];
    for (const auto& ch : magazine) ++magazine_hash[ch - 'a'];

    for (int i = 0; i < 26; ++i) {
      if (ransom_note_hash[i] != 0 && ransom_note_hash[i] > magazine_hash[i])
        return false;
    }
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE__H
