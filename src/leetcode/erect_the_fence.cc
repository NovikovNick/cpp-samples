#ifndef LEETCODE_ERECT_THE_FENCE_H
#define LEETCODE_ERECT_THE_FENCE_H
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
using Coord = std::vector<int>;
class Solution {
 public:
  vector<vector<int>> outerTrees(vector<Coord>& trees) {
    if (trees.size() <= 3) return trees;

    // 1. find min element
    std::rotate(
        trees.begin(),
        std::min_element(trees.begin(), trees.end(),
                         [](std::vector<int>& o1, std::vector<int>& o2) {
                           return o1[0] < o2[0];
                         }),
        trees.end());

    // 2. sort
    Coord yAxis{0, -100};
    std::sort(std::next(trees.begin()), trees.end(),
              [this, &min = trees[0], &yAxis = yAxis](std::vector<int>& o1,
                                                      std::vector<int>& o2) {
                float o1Angle = Angle(min, yAxis, o1);
                float o2Angle = Angle(min, yAxis, o2);
                if (o1Angle > o2Angle) return true;
                if (o1Angle == o2Angle) return Length(min, o1) < Length(min, o2);
                return false;
              });

    // 3. exclude
    auto a = trees.begin();
    auto b = std::next(a);
    auto c = std::next(b);
    while (c != trees.end()) {
      int product = CrossProduct(*a, *b, *c);

      std::cout << "[" << (*a)[0] << "," << (*a)[1] << "] [" << (*b)[0] << ","
                << (*b)[1] << "] x [" << (*a)[0] << "," << (*a)[1] << "] ["
                << (*c)[0] << "," << (*c)[1] << "] = " << product;

      if (product >= 0) {
        a = std::next(a);
        b = std::next(a);
        c = std::next(b);
        std::cout << " > 0\n";
      } else {
        a = trees.begin() == a ? a : std::prev(a);
        std::cout << " < 0 remove "
                  << "[" << (*b)[0] << "," << (*b)[1] << "]" << std::endl;
        trees.erase(b);
        b = std::next(a);
        c = std::next(b);
      }
    }
    return trees;
  }

  int CrossProduct(Coord& a, Coord& b, Coord& c) {
    return ((c[1] - a[1]) * (b[0] - a[0])) - ((c[0] - a[0]) * (b[1] - a[1]));
  }

  float Angle(Coord& pivot, Coord& a, Coord& b) {
    return DotProduct(pivot, a, b) / (Length(pivot, a) * Length(pivot, b));
  }

  float DotProduct(Coord& pivot, Coord& a, Coord& b) {
    float ax = a[0] - pivot[0];
    float ay = a[1] - pivot[1];
    float bx = b[0] - pivot[0];
    float by = b[1] - pivot[1];
    return ax * bx + ay * by;
  }

  float Length(Coord& pivot, Coord& a) {
    float ax = a[0] - pivot[0];
    float ay = a[1] - pivot[1];
    return std::sqrt(ax * ax + ay * ay);
  }

  void compare(vector<Coord>& trees) {
    Coord yAxis{0, 100};

    auto fst = trees.begin();
    auto snd = fst + 1;
    while (snd < trees.end()) {
      float fstProduct = Angle(trees[0], yAxis, *fst);
      float sndProduct = Angle(trees[0], yAxis, *snd);

      debug("[{:2d},{:2d}]({:3.3f}) ? [{:2d},{:2d}]({:3.3f})\n", (*fst)[0],
            (*fst)[1], fstProduct, (*snd)[0], (*snd)[1], sndProduct);

      ++fst;
      ++snd;
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ERECT_THE_FENCE_H
