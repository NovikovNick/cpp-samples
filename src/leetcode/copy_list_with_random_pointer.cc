#ifndef LEETCODE_COPY_LIST_WITH_RANDOM_POINTER_H
#define LEETCODE_COPY_LIST_WITH_RANDOM_POINTER_H
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

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    std::unordered_map<Node*, Node*> src2copy;
    std::vector<Node*> copied;
    int n = 0;
    Node* curr = head;
    while (curr) {
      auto copy = new Node(curr->val);
      src2copy[curr] = copy;
      copied.push_back(copy);

      curr = curr->next;
      ++n;
    }

    curr = head;
    int i = 0;
    while (curr) {
      if (i != n - 1) copied[i]->next = copied[i + 1];
      if (curr->random) copied[i]->random = src2copy[curr->random];

      curr = curr->next;
      ++i;
    }

    return copied[0];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COPY_LIST_WITH_RANDOM_POINTER_H
