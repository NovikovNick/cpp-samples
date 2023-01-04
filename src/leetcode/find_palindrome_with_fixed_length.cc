#ifndef LEETCODE_FIND_PALINDROME_WITH_FIXED_LENGTH_H
#define LEETCODE_FIND_PALINDROME_WITH_FIXED_LENGTH_H
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
  vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
    int n = queries.size();

    std::vector<long long> res(n);
    std::vector<int> num{0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < n; ++i) {
      if (queries[i] > maxPalindrome(intLength)) {
        res[i] = -1;
      } else {
        fill(queries[i], num);
        res[i] = kthPalindrome(intLength, num);
      }
    }
    return res;
  }

  long long kthPalindrome(int k, std::vector<int>& num) {
    long long res = 0;
    int i = 0;
    int order = 1;
    do {
      res += fst(k) * num[i] * order;
      order *= 10;
      k -= 2;
      ++i;
    } while (k > 0);
    return res;
  }

  inline int maxPalindrome(int k) { return std::pow(10, (k - 1) / 2) * 9; }

  void fill(int k, std::vector<int>& nums) {
    std::fill(nums.begin(), nums.end(), 0);
    k += 9;
    std::string str = std::to_string(k);
    for (int i = 0; i < str.size(); ++i) nums[i] = str[i] - '0';
  }

  inline long long fst(const int l) {
    return l < 2 ? 1 : std::pow(10, l - 1) + 1;
  }

  void print(std::vector<int>& nums) {
    for (const auto& num : nums) debug("{} ", num);
    debug("\n");
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_PALINDROME_WITH_FIXED_LENGTH_H
