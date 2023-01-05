#define DEBUG 1

#include <iostream>
#include <stack>
#include <thread>

#include "concurrency/hello_world.cc"
#include "concurrency/hierarchical_mutex.cc"
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

  /*
  std::mutex m1;
  std::mutex m2;
  std::scoped_lock g1(m1, m2);
  */

  concurrency::hierarchical_mutex m1000{1000};
  concurrency::hierarchical_mutex m500{500};
  std::scoped_lock g2(m500);
  std::scoped_lock g1(m1000);


  // concurrency::ScopedGuard g{std::thread(concurrency::run)};
  // throw std::runtime_error("!");
  // t.detach();
  return 0;
}
