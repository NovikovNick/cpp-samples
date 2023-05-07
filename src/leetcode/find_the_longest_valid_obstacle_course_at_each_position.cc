#ifndef LEETCODE_FIND_THE_LONGEST_VALID_OBSTACLE_COURSE_AT_EACH_POSITION_H
#define LEETCODE_FIND_THE_LONGEST_VALID_OBSTACLE_COURSE_AT_EACH_POSITION_H
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
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    std::stack<int> stack;  // increasing stack
    for (int i = 0; i < obstacles.size(); ++i) {
      while (!stack.empty() && stack.top() > obstacles[i]) stack.pop();
      stack.push(obstacles[i]);
      obstacles[i] = stack.size();
    }
    return obstacles;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_THE_LONGEST_VALID_OBSTACLE_COURSE_AT_EACH_POSITION_H
