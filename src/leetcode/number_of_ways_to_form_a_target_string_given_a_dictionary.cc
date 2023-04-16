#ifndef LEETCODE_NUMBER_OF_WAYS_TO_FORM_A_TARGET_STRING_GIVEN_A_DICTIONARY_H
#define LEETCODE_NUMBER_OF_WAYS_TO_FORM_A_TARGET_STRING_GIVEN_A_DICTIONARY_H
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
  int n, m;
  const int mod = 1e9 + 7;

 public:
  int numWays(vector<string>& words, string target) {
    n = words.size();
    m = words[0].size();
    return backtracking(0, 0, words, target);
  }

  long backtracking(int k, int begin, const vector<string>& words,
                         const string& target) {
    if (k == target.size()) return 1;

    int res = 0;
    for (int row = 0; row < n; ++row) {
      for (int col = begin; col < m; ++col) {
        if (words[row][col] == target[k])
          res += backtracking(k + 1, col + 1, words, target) % mod;
      }
    }
    return res;
  }
};

}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_WAYS_TO_FORM_A_TARGET_STRING_GIVEN_A_DICTIONARY_H
