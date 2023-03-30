#ifndef LEETCODE_SCRAMBLE_STRING_H
#define LEETCODE_SCRAMBLE_STRING_H
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

struct Letter {
  char letter;
  int pos;
  int compare;
};

class Solution {
  std::vector<int> s1_hash, s2_hash;

 public:
  Solution() : s1_hash(std::vector<int>(26)), s2_hash(std::vector<int>(26)) {}
  bool isScramble(string s1, string s2) {
    for (const auto& it : s1) ++s1_hash[it - 'a'];
    for (const auto& it : s2) ++s2_hash[it - 'a'];
    if (s1_hash != s2_hash) return false;

    std::fill(s1_hash.begin(), s1_hash.end(), -1);
    std::fill(s2_hash.begin(), s2_hash.end(), -1);
    int n = s1.size();


    for (int i = 0; i < n; ++i) s1_hash[s1[i] - 'a'] = i;
    for (int i = 0; i < n; ++i) s2_hash[s2[i] - 'a'] = i;
    print(s1_hash);
    print(s2_hash);
    return true;
  }

  void print(std::vector<int>& hash) {
    for (int i = 0; i < hash.size(); ++i) {
      if (hash[i] >= 0) {
        debug("{} - {}\n", static_cast<char>(i + 'a'), hash[i]);
      }
    }
    debug(" --- \n");
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SCRAMBLE_STRING_H
