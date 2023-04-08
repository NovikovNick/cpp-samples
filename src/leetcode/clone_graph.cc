#ifndef LEETCODE_CLONE_GRAPH_H
#define LEETCODE_CLONE_GRAPH_H
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

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;

    std::vector<Node*> nodes(100, nullptr);
    nodes[node->val - 1] = new Node(node->val);

    std::stack<Node*> stack;
    stack.push(node);

    while (stack.size()) {
      auto n = stack.top();
      stack.pop();

      for (auto neighbor : n->neighbors) {
        if (nodes[neighbor->val - 1] == nullptr) {
          nodes[neighbor->val - 1] = new Node(neighbor->val);
          stack.push(neighbor);
        }
        nodes[n->val - 1]->neighbors.push_back(nodes[neighbor->val - 1]);
      }
    }
    return nodes[0];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CLONE_GRAPH_H
