#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_LARGEST_RECTANGLE_IN_HISTOGRAM_H
#define LEETCODE_LARGEST_RECTANGLE_IN_HISTOGRAM_H

namespace leetcode {

using namespace std;

struct my_pair {
  int key;
  mutable int val;
};

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    auto comp = [](my_pair p1, my_pair p2) -> bool { return p1.key < p2.key; };
    std::set<my_pair, decltype(comp)> set(comp);

    for (auto height : heights) {
      auto [pos, added] = set.insert({height, 0});
      // std::cout << "1. curr: " << pos->key << ":" << pos->val << std::endl;
      auto bound = std::next(pos);
      
      if (added && bound != set.end()) {
        // std::cout << "2. added prevs: " << bound->key << ":" << bound->val << std::endl;
        pos->val += bound->val;
      }

      while (bound != set.end()) {
        // std::cout << "3. remove prevs: " << bound->key << "-" << bound->val << std::endl;
        auto next = std::next(bound);
        set.erase(bound);
        bound = next;
      }

      //std::cout << "added and calculate { ";
      for (auto it = std::make_reverse_iterator(bound),
                last = std::make_reverse_iterator(set.begin());
           it != last; ++it) {
        it->val++;
        maxArea = std::max(maxArea, it->val * it->key);
        //std::cout << it->key << "(" << it->val << ") ";
      }
      //std::cout << "}\n";
      //std::cout << " total = " << maxArea << std::endl;
    }

    //std::cout << " ================================================= " << maxArea << std::endl;
    return maxArea;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LARGEST_RECTANGLE_IN_HISTOGRAM_H
