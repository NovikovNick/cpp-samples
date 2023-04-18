#ifndef LEETCODE_MERGE_STRINGS_ALTERNATELY_H
#define LEETCODE_MERGE_STRINGS_ALTERNATELY_H
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
  string mergeAlternately(string word1, string word2) {
    std::string res;
    int fst = 0, snd = 0;

    int n = std::min(word1.size(), word2.size()) * 2;
    for (int i = 0; i < n; ++i) res += i & 1 ? word2[snd++] : word1[fst++];

    if (fst < word1.size()) res.append(word1.substr(fst));
    if (snd < word2.size()) res.append(word2.substr(snd));

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MERGE_STRINGS_ALTERNATELY_H
