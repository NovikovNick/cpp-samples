#ifndef LEETCODE_REVERSE_VOWELS_OF_A_STRING_H
#define LEETCODE_REVERSE_VOWELS_OF_A_STRING_H
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace leetcode {

using namespace std;

class Solution {
  std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                  'A', 'E', 'I', 'O', 'U'};

  inline bool IsVowel(std::string::iterator iter) const {
    return vowels.find(*iter) != vowels.end();
  }

 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  string reverseVowels(string s) {
    auto it = s.begin();
    auto revIt = std::prev(s.end());
    while (it < revIt) {
      while (!IsVowel(it) && it < revIt) ++it;
      while (!IsVowel(revIt) && it < revIt) --revIt;
      if (it < revIt) std::iter_swap(it, revIt);
      ++it;
      --revIt;
    };
    return s;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REVERSE_VOWELS_OF_A_STRING_H
