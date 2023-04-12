#ifndef LEETCODE_SIMPLIFY_PATH_H
#define LEETCODE_SIMPLIFY_PATH_H
#include <algorithm>
#include <deque>
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
  string simplifyPath(string path) {
    debug("Path: {}\n", path);
    std::deque<std::string> queue;
    std::string dir;

    for (const auto ch : path) {
      if (ch == '/') {
        if (dir == ".") {
          dir.erase();
        } else if (dir == "..") {
          if (!queue.empty()) queue.pop_front();
          dir.erase();
        } else if (!dir.empty()) {
          queue.push_front(dir);
          dir.erase();
        }
      } else {
        dir += ch;
      }
    }

    if (dir == ".") {
    } else if (dir == "..") {
      if (!queue.empty()) queue.pop_front();
    } else if (!dir.empty()) {
      queue.push_front(dir);
    }

    path.erase();
    while (!queue.empty()) {
      path.append("/" + queue.back());
      queue.pop_back();
    }
    return path.empty() ? "/" : path;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SIMPLIFY_PATH_H
