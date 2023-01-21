#define DEBUG 1

#include <bitset>
#include <future>
#include <iostream>
#include <stack>
#include <thread>
#include <vector>

#include "snake_game_sample/ggpo_samples.h"
#include "util/log.h"

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

  int fst_player = (1 << 4);
  int snd_player = (2 << 4);

  int up = 0b00000000;
  int down = (2 << 0);
  int bottom = (1 << 0);

  /*int num = 0 | dir_lft;
  std::cout << (dir_btm == (num & dir_msk)) << std::endl;*/
  ggpo::GridCell cell(1);
  std::cout << sizeof(cell) << std::endl;
  std::cout << std::bitset<8>(cell.data) << std::endl;
  std::cout << cell.isEmpty() << std::endl;


  ggpo::Callbacks cb{0};
  cb.load_game_state = ggpo::loadGameState;
  cb.save_game_state = ggpo::saveGameState;
  ggpo::Launcher(cb).start();
  return 0;
}
