#ifndef LEETCODE_MINIMUM_GENETIC_MUTATION_H
#define LEETCODE_MINIMUM_GENETIC_MUTATION_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
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

class Solution {
  using DTO = std::tuple<std::string, int, int>;
  int gen_size = 8;
  std::string gens{"ACGT"};

 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int minMutation(string startGene, string endGene, vector<string>& bank) {
    std::unordered_map<std::string, int> dp;
    for (const auto& gen : bank) dp[gen] = INT_MAX;

    auto comp = [](const DTO& o1, const DTO& o2) {
      const auto& [_, dis1, diff1] = o1;
      const auto& [__, dis2, diff2] = o2;
      if (dis1 > dis2) return true;
      if (dis1 == dis2) return diff1 > diff2;
      return false;
    };
    std::priority_queue<DTO, std::vector<DTO>, decltype(comp)> queue(comp);

    auto it = dp.find(endGene);
    if (it != dp.end()) {
      queue.push(DTO(endGene, 1, Diff(endGene, startGene)));
    } else {
      return -1;
    }

    while (!queue.empty()) {
      auto [gen, mut, diff] = queue.top();
      queue.pop();
      // debug("PQ:{} - {} mutations - {} diff\n", gen, mut, diff);

      for (int i = 0; i < gen_size; ++i) {
        for (auto ch : gens) {
          auto new_gen = gen;
          new_gen[i] = ch;
          auto it = dp.find(new_gen);
          if (new_gen == startGene) {
            // debug("Found {} with mutations!\n", new_gen, mut);
            return mut;
          }
          if (ch != gen[i] && it != dp.end() && it->second > (mut + 1)) {
            queue.push(DTO(new_gen, mut + 1, Diff(new_gen, startGene)));
          }
        }
      }
    }

    return -1;
  }

 private:
  int Diff(const std::string& o1, const std::string& o2) {
    int res = 0;
    for (int i = 0; i < gen_size; ++i) {
      if (o1[i] != o2[i]) ++res;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_GENETIC_MUTATION_H
