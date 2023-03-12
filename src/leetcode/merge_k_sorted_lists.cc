#ifndef LEETCODE_MERGE_K_SORTED_LISTS_H
#define LEETCODE_MERGE_K_SORTED_LISTS_H
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
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    std::vector<ListNode*> nodes(1e4);
    int i = 0;
    for (auto node : lists) {
      while (node) {
        nodes[i++] = node;
        node = node->next;
      }
    }
    if (i == 0) return nullptr;

    std::sort(nodes.begin(), nodes.begin() + i,
              [](const ListNode* lhs, const ListNode* rhs) {
                return lhs->val < rhs->val;
              });

    for (int j = 1; j < i; ++j) nodes[j - 1]->next = nodes[j];
    nodes[i - 1]->next = nullptr;
    return nodes[0];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MERGE_K_SORTED_LISTS_H
