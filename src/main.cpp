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
  const double pi = std::acos(-1);

  float fst = 0.2;
  if (fst != 0.2) std::cout << "problem with floating point\n";

  return 0;
}
