#ifndef LEETCODE_CONSTRUCT_QUAD_TREE_H
#define LEETCODE_CONSTRUCT_QUAD_TREE_H
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

class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
       Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
  using MATRIX = std::vector<std::vector<int>>;

 public:
  Node* construct(MATRIX& grid) { return dfs(0, 0, grid.size(), grid); }

  Node* dfs(const int x, const int y, int n, const MATRIX& grid) {
    if (n == 1) return new Node(grid[y][x], true);
    n >>= 1;  // i.e. n = n / 2;
    auto tl = dfs(x, y, n, grid);
    auto tr = dfs(x + n, y, n, grid);
    auto bl = dfs(x, y + n, n, grid);
    auto br = dfs(x + n, y + n, n, grid);
    if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
        tl->val == tr->val && tr->val == bl->val && bl->val == br->val)
      return tl;
    return new Node(1, false, tl, tr, bl, br);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CONSTRUCT_QUAD_TREE_H
