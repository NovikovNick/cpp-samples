#ifndef LEETCODE_FIND_CLOSEST_NODE_TO_GIVEN_TWO_NODES_H
#define LEETCODE_FIND_CLOSEST_NODE_TO_GIVEN_TWO_NODES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_set>
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
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    std::unordered_set<int> hashset_1, hashset_2;
    std::vector<int> distances_1(n, 0), distances_2(n, 0);
    bool has_elem_1 = true, has_elem_2 = true;
    int res = -1;
    int dist1 = 0, dist2 = 0;
    while (has_elem_1 || has_elem_2) {
      if (has_elem_1) {
        debug("1-{} ", node1);
        auto [it, inserted] = hashset_1.insert(node1);
        if (inserted) {
          distances_1[node1] = hashset_1.size();
          if (contains(hashset_2, node1)) {
            if (res == -1 || (distances_1[node1] + distances_2[node1]) > (distances_1[res] + distances_2[res])) {
              res = node1;
            } else if ((distances_1[node1] + distances_2[node1]) == (distances_1[res] + distances_2[res])) {
              res = std::min(node1, res);
            }
          };
          node1 = edges[node1];
          has_elem_1 = node1 != -1;
        } else {
          has_elem_1 = false;
        }
      }
      if (has_elem_2) {
        debug("2-{} ", node2);
        auto [it, inserted] = hashset_2.insert(node2);
        if (inserted) {
          distances_2[node2] = hashset_2.size();
          if (contains(hashset_1, node2)) {
            if (res == -1 || (distances_1[node2] + distances_2[node2]) > (distances_1[res] + distances_2[res])) {
              res = node2;
            } else if ((distances_1[node2] + distances_2[node2]) == (distances_1[res] + distances_2[res])) {
              res = std::min(node2, res);
            }
          };
          node2 = edges[node2];
          has_elem_2 = node2 != -1;
        } else {
          has_elem_2 = false;
        }
      }
      debug("res = {}\n", res);
    }
    return res;
  }

  inline bool contains(const std::unordered_set<int>& hashset, const int& val) {
    return hashset.find(val) != hashset.end();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_CLOSEST_NODE_TO_GIVEN_TWO_NODES_H
