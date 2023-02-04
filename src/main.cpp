#define DEBUG 1

#include <bitset>
#include <future>
#include <iostream>
#include <queue>
#include <stack>
#include <thread>
#include <vector>

#include "algorithm/backtracking.cc"
#include "algorithm/bit_manipulation.cc"
#include "algorithm/heap.cc"
#include "algorithm/sorting.cc"
#include "concurrency/chrono.cc"
#include "snake_game_sample/ggpo_samples.h"
#include "util/log.h"

/*
1. dfs and bfs
2. dp or update input array to avoid redundant calculation
3. monotonic stack. Track min/max elements
4. heap for max/min element for O(1). Insersion and deletion for O(logN)
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
12. Whenever you have a problem where you need to check the
    subsequences/combinations/permutations of some group of letters/numbers, the
    first thought you should have is backtracking. Backtracking - поиск с
    возвратом.
13. std::list<int> - double linked list. Adding, removing and moving the
    elements within the list or across several lists does not invalidate the
    iterators or references.
14. Insertion sort best choice for small array(less then 15) or on almost sorted
    arrays.
15. Counting sort is all about using a predefined range of keys and track
    frequency of each value. Then overwrite count with the starting index and
then shift index by count.
16. Custom specialization of std::hash can be injected in namespace std
    namespace std {
    template <>
    struct std::hash<S> {
      size_t operator()(const S& s) const {
        std::size_t h1 = std::hash<int>{}(s.x);
        std::size_t h2 = std::hash<int>{}(s.y);
        return h1 == h2 ? h1 : h1 ^ h2;
      }
    };
    }
*/

void print(auto begin, auto end) {
  while (begin != end) {
    util::debug("{} ", *begin);
    begin = std::next(begin);
  }
  util::debug("\n");
}

class Base {
 public:
  virtual ~Base() = default;
  virtual void foo() = 0;
};

class Derrived : public Base {
 public:
  void foo() override;
};

void Derrived::foo() { util::debug("it works..."); };

int main(int argc, char* argv[]) {
  std::cout << "This thread id is " << std::this_thread::get_id() << std::endl;
  util::debug("{} of the threads can run concurrently.\n",
              std::thread::hardware_concurrency());

  std::vector<int> nums{1, 2, 3, 3, 3, 3, 2, 3, 1, 1, 2,
                        3, 2, 1, 2, 2, 1, 3, 3, 3, 1};
  print(nums.begin(), nums.end());
  countingSort(nums.begin(), nums.end());
  print(nums.begin(), nums.end());

  std::shared_ptr<Base> base = std::make_shared<Derrived>();
  base->foo();

  return 0;
}
