#ifndef LEETCODE_EXTRA_CHARACTERS_IN_A_STRING_H
#define LEETCODE_EXTRA_CHARACTERS_IN_A_STRING_H
#include <algorithm>
#include <format>
#include <iostream>
#include <optional>
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
  int minExtraChar(string s, vector<string>& dictionary) {
    std::vector<std::pair<int, int>> intervals;
    for (const auto& word : dictionary) {
      if (auto interval_opt = find(word, s)) {
        intervals.push_back(interval_opt.value());
      }
    }
    std::sort(intervals.begin(), intervals.end());

    int res = s.size();
    for (auto [begin, end] : intervals) {
      res = std::min(res, begin);
      debug("{}: [{}, {}]\n", s.substr(begin, end - begin + 1), begin, end);
    }

    return res;
  }

  std::optional<std::pair<int, int>> find(std::string_view search,
                                          std::string_view base) const noexcept {
    int begin = 0;
    int size = 0;
    for (int i = 0; i < base.size(); ++i) {
      if (base[i] == search[size]) {
        if (size == search.size() - 1) {
          return std::make_optional<std::pair<int, int>>({begin, begin + size});
        }

        ++size;

      } else {
        begin = i + 1;
        size = 0;
      }
    }
    return std::nullopt;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_EXTRA_CHARACTERS_IN_A_STRING_H
