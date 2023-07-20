#ifndef LEETCODE_ASTEROID_COLLISION_H
#define LEETCODE_ASTEROID_COLLISION_H
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
  vector<int> asteroidCollision(vector<int>& asteroids) {
    std::stack<int> stack;
    for (const auto asteroid : asteroids) {
      while (!resolveCollision(stack, asteroid)) {
      }
    }

    std::vector<int> res(stack.size());
    for (int i = stack.size() - 1; i >= 0; --i) {
      res[i] = stack.top();
      stack.pop();
    }
    return res;
  }

  static bool resolveCollision(std::stack<int>& stack, const int asteroid) {
    if (stack.empty() 
        || (sign(stack.top()) == sign(asteroid)) 
        || (stack.top() < 0 && asteroid > 0)) {
      stack.push(asteroid);
      return true;
    } else if (std::abs(stack.top()) == std::abs(asteroid)) {
      stack.pop();
      return true;
    } else if (std::abs(stack.top()) < std::abs(asteroid)) {
      stack.pop();
      return false;
    } else {
      return true;
    }
  }

  inline static bool sign(const int num) {
    return std::signbit(static_cast<double>(num));
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ASTEROID_COLLISION_H
