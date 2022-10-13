#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_LETTER_CASE_PERMUTATION_H
#define LEETCODE_LETTER_CASE_PERMUTATION_H

namespace leetcode {

using namespace std;

template <typename InputIterator>
void permutate(InputIterator pos, InputIterator end,
               std::vector<std::string>& out, std::string str) {
  if (pos == end) {
    out.push_back(str);
    return;
  }

  auto ch = *pos;
  ++pos;
  if (std::isalpha(ch)) {
    std::string upperCase{static_cast<char>(std::toupper(ch))};
    std::string lowerCase{static_cast<char>(std::tolower(ch))};
    permutate(pos, end, out, str + upperCase);
    permutate(pos, end, out, str + lowerCase);
  } else {
    std::string digit{ch};
    permutate(pos, end, out, str + digit);
  }

}

class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    std::vector<std::string> res;
    permutate(s.begin(), s.end(), res, "");
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LETTER_CASE_PERMUTATION_H
