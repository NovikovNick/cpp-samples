#ifndef LEETCODE_STRING_COMPRESSION_H
#define LEETCODE_STRING_COMPRESSION_H
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
  int compress(vector<char>& chars) {
    int size = 0;
    auto fst = chars.begin();
    auto cur = fst;
    auto snd = std::next(fst);
    int duplicate_count = 1;
    while (snd != chars.end()) {
      if (*fst == *snd) {
        ++duplicate_count;
        ++snd;
      } else {
        *cur = *fst;
        int offset = write(cur, duplicate_count);
        size += offset + 1;
        cur += offset + 1;
        duplicate_count = 1;
        fst = snd;
        ++snd;
      }
    }

    *cur = *fst;
    size += 1;
    size += write(cur, duplicate_count);

    return size;
  }

  int write(std::vector<char>::iterator begin, const int nums) {
    if (nums == 1) return 0;
    auto nums_str = std::to_string(nums);
    for (const auto& num : nums_str) {
      ++begin;
      *begin = num;
    }
    return nums_str.size();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_STRING_COMPRESSION_H
