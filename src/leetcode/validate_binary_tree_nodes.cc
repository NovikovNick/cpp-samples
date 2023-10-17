#ifndef LEETCODE_VALIDATE_BINARY_TREE_NODES_H
#define LEETCODE_VALIDATE_BINARY_TREE_NODES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

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
  bool validateBinaryTreeNodes(int n,
                               vector<int>& leftChild,
                               vector<int>& rightChild) {
    std::unordered_set<int> hashset;
    for (int i = 0; i < n; ++i) {
      if (leftChild[i] != -1) {
        if (!hashset.insert(leftChild[i]).second) {
          return false;
        }
      };

      if (rightChild[i] != -1) {
        if (!hashset.insert(rightChild[i]).second) {
          return false;
        }
      };
    }

    if (hashset.size() != n - 1) {
      return false;
    }

    int root = 0;
    for (; root < n && hashset.find(root) != hashset.end(); ++root) {
    }

    std::stack<int> dfs;
    dfs.push(root);
    while (!dfs.empty()) {
      auto node = dfs.top();
      dfs.pop();

      hashset.erase(node);

      if (rightChild[node] != -1) {
        dfs.push(rightChild[node]);
      }

      if (leftChild[node] != -1) {
        dfs.push(leftChild[node]);
      }
    }

    return hashset.empty();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_VALIDATE_BINARY_TREE_NODES_H
