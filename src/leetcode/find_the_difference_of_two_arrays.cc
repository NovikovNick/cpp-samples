#ifndef LEETCODE_FIND_THE_DIFFERENCE_OF_TWO_ARRAYS_H
#define LEETCODE_FIND_THE_DIFFERENCE_OF_TWO_ARRAYS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_set>
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
  /*vector<vector<int>> findDifference(vector<int>& n1, vector<int>& n2) {
    return {diff(n1, n2), diff(n2, n1)};
  }

  std::vector<int> diff(vector<int>& lhs, vector<int>& rhs) {
    std::unordered_set<int> hash(rhs.begin(), rhs.end()), res;
    for (const auto it : lhs)
      if (hash.find(it) == hash.end()) res.insert(it);
    return std::vector<int>(res.begin(), res.end());
  }*/

  vector<vector<int>> findDifference(vector<int> & n1, vector<int> & n2) {
    std::vector<std::vector<int>> res(2);
    std::sort(n1.begin(), n1.end());
    std::sort(n2.begin(), n2.end());
    diff(n1, n2, res[0]);
    diff(n2, n1, res[1]);
    return res;
  }

  void diff(const std::vector<int>& lhs, const std::vector<int>& rhs,
            std::vector<int>& out) {
    auto lhs_it = lhs.begin();
    auto rhs_it = rhs.begin();
    while (lhs_it != lhs.end()) {
      if (rhs_it == rhs.end()) {
        std::unique_copy(lhs_it, lhs.end(), std::back_inserter(out));
        return;
      }

      if (*lhs_it > *rhs_it) {
        ++rhs_it;
      } else if (*lhs_it <= *rhs_it) {
        if (*lhs_it < *rhs_it && (out.empty() || out.back() != *lhs_it))
          out.emplace_back(*lhs_it);
        ++lhs_it;
      }
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_THE_DIFFERENCE_OF_TWO_ARRAYS_H
