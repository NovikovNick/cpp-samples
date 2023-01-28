#include <numeric>

#include "../util/log.h"

/*
  Combinator combinator;
  int n = 4, k = 3;
  for (const auto& combination : combinator.combine(4, 3)) {
    util::debug("combination: ");
    for (const auto num : combination) util::debug("{:3d}", num);
    util::debug("\n");
  }
*/
class Combinator {
  using SEQUENCE = std::vector<int>;
  using COMBINATION = std::vector<int>;
  using COMBINATIONS = std::vector<COMBINATION>;

 public:
  COMBINATIONS combine(int n, int k) {
    SEQUENCE sq(n);
    std::iota(sq.begin(), sq.end(), 1);
    COMBINATIONS res;
    COMBINATION curr;
    backtracking(0, sq, k, res, curr);
    return res;
  }

 private:
  void backtracking(int i, const SEQUENCE& sq, const int k, COMBINATIONS& res,
                    COMBINATION& curr) {
    if (curr.size() == k) {
      res.push_back(curr);
      return;
    }
    for (; i < sq.size(); ++i) {
      curr.push_back(sq[i]);
      backtracking(i + 1, sq, k, res, curr);
      curr.pop_back();
    }
  }
};