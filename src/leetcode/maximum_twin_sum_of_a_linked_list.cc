#ifndef LEETCODE_MAXIMUM_TWIN_SUM_OF_A_LINKED_LIST_H
#define LEETCODE_MAXIMUM_TWIN_SUM_OF_A_LINKED_LIST_H
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
  int pairSum(ListNode* head) {
    int n = findN(head);

    std::vector<int> arr(n);
    fillArray(head, arr, n);

    return pairSum(arr, n);
  }

  int findN(ListNode* node) {
    int n = 0;
    while (node) {
      ++n;
      node = node->next;
    }
    return n;
  }

  void fillArray(ListNode* node, std::vector<int>& arr, const int n) {
    for (int i = 0; i < n; ++i, node = node->next) arr[i] = node->val;
  }

  int pairSum(const std::vector<int>& arr, const int n) {
    int res = 0;
    int threshold = n / 2 - 1;
    for (int i = 0; i <= threshold; ++i) {
      res = std::max(res, arr[i] + arr[n - 1 - i]);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_TWIN_SUM_OF_A_LINKED_LIST_H
