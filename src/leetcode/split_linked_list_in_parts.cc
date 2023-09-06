#ifndef LEETCODE_SPLIT_LINKED_LIST_IN_PARTS_H
#define LEETCODE_SPLIT_LINKED_LIST_IN_PARTS_H
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
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    std::vector<ListNode*> res(k, nullptr);
    if (!head) return res;

    int n = getDistance(head);
    std::vector<int> values(n);

    copyValues(head, values);
    initParts(res, head, n, k);
    copyValues(values, res);

    return res;
  }

  int getDistance(ListNode* node) {
    int dist = 0;
    while (node) {
      node = node->next;
      ++dist;
    }
    return dist;
  }

  void copyValues(ListNode* src_node, std::vector<int>& dst) {
    int i = 0;
    while (src_node) {
      dst[i++] = src_node->val;
      src_node = src_node->next;
    }
  }

  void copyValues(const std::vector<int>& src, std::vector<ListNode*>& dst) {
    int i = 0;
    ListNode* node = dst[i];
    for (const auto val : src) {
      if (!node) node = dst[++i];
      node->val = val;
      node = node->next;
    }
  }

  void initParts(std::vector<ListNode*>& res,
                 ListNode* node,
                 const int size,
                 const int partsCount) {
    ListNode* next;
    for (int i = 0; i < size; ++i) {
      next = node->next;
      node->next = res[i % partsCount];
      res[i % partsCount] = node;
      node = next;
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SPLIT_LINKED_LIST_IN_PARTS_H
