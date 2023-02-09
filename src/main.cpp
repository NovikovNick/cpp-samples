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

void print(auto begin, auto end) {
  while (begin != end) {
    util::debug("{} ", *begin);
    begin = std::next(begin);
  }
  util::debug("\n");
}

/// <summary>
/// Calculate bucket index for specific collection size
/// </summary>
/// <param name="bucket_count"></param>
/// <param name="curr_index"></param>
/// <param name="collection_size"></param>
/// <returns></returns>
inline int bucket(int bucket_count, int curr_index, int collection_size) {
  return bucket_count * curr_index / collection_size;
}

int main(int argc, char* argv[]) {
  std::cout << "This thread id is " << std::this_thread::get_id() << std::endl;
  util::debug("{} of the threads can run concurrently.\n",
              std::thread::hardware_concurrency());

  std::vector<int> nums{-100,200,2,1,2,34,563,346,100000};
  print(nums.begin(), nums.end());
  bucketSort(nums.begin(), nums.end(), 5);
  print(nums.begin(), nums.end());

  util::debug("num {}\n", 1e4);

  auto l = convert(1, 2);
  auto [lhs, rhs] = convert(l);
  util::debug("{} + {} = {}\n", 1, 2, convert(1, 2));
  util::debug("{} = {} + {}\n", l, lhs, rhs);

  return 0;
}
