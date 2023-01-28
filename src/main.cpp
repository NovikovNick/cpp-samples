#define DEBUG 1

#include <bitset>
#include <future>
#include <iostream>
#include <stack>
#include <thread>
#include <vector>

#include "snake_game_sample/ggpo_samples.h"
#include "util/log.h"
#include "concurrency/chrono.cc"
#include "algorithm/backtracking.cc"

/*
1. dfs and bfs
2. dp or update input array to avoid redundant calculation
3. monotonic stack. Track min/max elements
4. heap for max/min element for O(1)
5. binary search. Lower bound. Upper bound.
6. Union find - Ranks?
7. DP for finding common subsequence. Try to find DP formula in math notation

8. don't forget to use priority_queue<int> heap(piles.begin(), piles.end());
9. don't forget to use int totalSum = accumulate(piles.begin(), piles.end(), 0);

10. bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        for (const auto& num : nums)
            if (set.insert(num).second == false) return false;
        return true;
    }
11. binary search tree traversal: preorder, inorder, postorder
12. Whenever you have a problem where you need to check the subsequences/combinations/permutations of some group of letters/numbers, the first thought you should have is backtracking. Backtracking - поиск с возвратом.

*/

int main(int argc, char* argv[]) {
  std::cout << "This thread id is " << std::this_thread::get_id() << std::endl;
  util::debug("{} of the threads can run concurrently.\n",
              std::thread::hardware_concurrency());
  // sample_concur::startGameLoop();

  Combinator combinator;
  int n = 4, k = 3;
  for (const auto& combination : combinator.combine(4, 3)) {
    util::debug("combination: ");
    for (const auto num : combination) util::debug("{:3d}", num);
    util::debug("\n");
  }
  return 0;
}
