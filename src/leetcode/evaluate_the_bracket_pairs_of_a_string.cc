#ifndef LEETCODE_EVALUATE_THE_BRACKET_PAIRS_OF_A_STRING_H
#define LEETCODE_EVALUATE_THE_BRACKET_PAIRS_OF_A_STRING_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
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
  string evaluate(string s, vector<vector<string>>& knowledge) {
    int n = s.size();
    std::unordered_map<std::string, std::string> map;
    for (const auto& it : knowledge) map[it[0]] = it[1];

    std::string res;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        std::string key;
        int j = i;
        while (s[j + 1] != ')') key += s[++j];

        auto it = map.find(key);
        res += it != map.end() ? it->second : "?";

        i = j + 1;

      } else {
        res += s[i];
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_EVALUATE_THE_BRACKET_PAIRS_OF_A_STRING_H
