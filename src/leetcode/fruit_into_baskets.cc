#ifndef LEETCODE_FRUIT_INTO_BASKETS_H
#define LEETCODE_FRUIT_INTO_BASKETS_H
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

class TwoBuckets final {
  std::vector<int> buckets;
  std::vector<int> types;

 public:
  TwoBuckets()
      : buckets(std::vector<int>(2, 0)), types(std::vector<int>(2, -1)){};

  inline void put(const int type) {
    if (types[0] == type) {
      ++buckets[0];
    } else if (types[1] == type) {
      ++buckets[1];
    } else if (types[0] == -1) {
      types[0] = type;
      buckets[0] = 1;
    } else if (types[1] == -1) {
      types[1] = type;
      buckets[1] = 1;
    };
  }

  inline void pop(const int type) {
    if (types[0] == type) {
      if (--buckets[0] == 0) types[0] = -1;
    } else if (types[1] == type) {
      if (--buckets[1] == 0) types[1] = -1;
    }
  }

  inline bool hasSpace(const int type) {
    if (types[0] == type || types[0] == -1) return true;
    if (types[1] == type || types[1] == -1) return true;
    return false;
  }
};

class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    if (n < 2) return n;

    TwoBuckets buckets;
    buckets.put(fruits[0]);
    buckets.put(fruits[1]);
    int counts = 2;
    int res = counts;
    for (int left = 0, right = 2; right < n; ++right) {
      while (!buckets.hasSpace(fruits[right])) {
        buckets.pop(fruits[left]);
        ++left;
        --counts;
      }
      buckets.put(fruits[right]);
      res = std::max(res, ++counts);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FRUIT_INTO_BASKETS_H
