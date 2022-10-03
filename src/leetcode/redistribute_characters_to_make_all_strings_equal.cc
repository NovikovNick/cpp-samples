#include <iostream>
#include <vector>
#include <algorithm>

#ifndef LEETCODE_REDISTRIBUTE_CHARACTERS_TO_MAKE_ALL_STRINGS_EQUAL_H
#define LEETCODE_REDISTRIBUTE_CHARACTERS_TO_MAKE_ALL_STRINGS_EQUAL_H

namespace leetcode {

using namespace std;

class Solution {
 public:
  bool makeEqual(vector<string>& words) {
    std::vector<int> hash(26, 0);

    for (auto word : words) {
      for (auto letter : word) {
        ++hash[(static_cast<int>(letter) - static_cast<int>('a'))];
      }
    }

    return std::all_of(
        hash.cbegin(), hash.cend(),
        [size = words.size()](int const it) { return it % size == 0; });
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REDISTRIBUTE_CHARACTERS_TO_MAKE_ALL_STRINGS_EQUAL_H
