#define DEBUG 1

#include <future>
#include <iostream>
#include <stack>
#include <thread>
#include <vector>

#include "concurrency/chrono.cc"
#include "concurrency/barrier.cc"
#include "concurrency/sort.cc"
#include "util/log.h"
/*
1. backtracking: dfs and bfs
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
 11.
*/

int main(int argc, char* argv[]) {
  std::cout << "This thread id is " << std::this_thread::get_id() << std::endl;
  util::debug("{} of the threads can run concurrently.\n",
              std::thread::hardware_concurrency());

  // sample_concur::startGameLoop();
  // sample_concur::quick_sort_sample();

  sample_concur::when_all_sample();
  return 0;
}
