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

/*
  Permutator permutator;
  std::vector<int> nums{1, 2, 3};
  for (const auto& permutation : permutator.permute(nums)) {
    util::debug("permutation: ");
    for (const auto num : permutation) util::debug("{:3d}", num);
    util::debug("\n");
  }
*/
class Permutator {
  using PERMUTATION = std::vector<int>;
  using PERMUTATIONS = std::vector<PERMUTATION>;

 public:
  PERMUTATIONS permute(PERMUTATION& nums) {
    PERMUTATIONS res;
    /*
    // STD solution
    std::sort(nums.begin(), nums.end());
    do {
      res.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));
    */
    backtracking(0, nums, res);
    return res;
  }

 private:
  void backtracking(const int begin, PERMUTATION& nums, PERMUTATIONS& res) {
    if (begin == nums.size()) {
      res.push_back(nums);
      return;
    }
    for (int i = begin; i < nums.size(); ++i) {
      std::swap(nums[begin], nums[i]);
      backtracking(begin + 1, nums, res);
      std::swap(nums[begin], nums[i]);
    }
  }
};