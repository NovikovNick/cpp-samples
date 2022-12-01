#ifndef LEETCODE_LARGEST_RECTANGLE_IN_HISTOGRAM_H
#define LEETCODE_LARGEST_RECTANGLE_IN_HISTOGRAM_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int largestRectangleArea(vector<int>& heights) {
    int max_area = 0, n = heights.size();

    std::stack<int> stack;  // monotonic asc stack
    stack.push(heights[0]);

    for (int i = 1; i <= n; ++i) {
      auto height = i == n ? 0 : heights[i];
      int count = 1;
      // debug("{}. height = {}, max = {}\n", i, height, max_area);
      while (!stack.empty() && height < stack.top()) {
        max_area = std::max(max_area, stack.top() * count);
        // debug(" ====> top = {}, max = {}\n", stack.top(), max_area);
        stack.pop();
        ++count;
      }
      while (count-- > 0) stack.push(height);
    }
    return max_area;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LARGEST_RECTANGLE_IN_HISTOGRAM_H
