#ifndef LEETCODE_UNIQUE_NUMBER_OF_OCCURRENCES_H
#define LEETCODE_UNIQUE_NUMBER_OF_OCCURRENCES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
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
  bool uniqueOccurrences(vector<int>& arr) {
    std::unordered_map<int, int> occurrences;
    for (const auto& it : arr) ++occurrences[it];

    std::unordered_set<int> unique_occurrences;
    for (const auto& [key, val] : occurrences) unique_occurrences.insert(val);
    
    return (unique_occurrences.size() == occurrences.size());
  }
};
}  // namespace leetcode
#endif  // LEETCODE_UNIQUE_NUMBER_OF_OCCURRENCES_H
