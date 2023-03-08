#define DEBUG 1

#include <algorithm>
#include <bitset>
#include <future>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <thread>
#include <vector>

#include "algorithm/binary_search.cc"
#include "concurrency/chrono.cc"
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

  // 1.
  float fst = 0.2;
  if (fst != 0.2) std::cout << "fst is float, but '0.2' is double\n";

  // 2.
  std::vector<float> floats(100);
  for (int i = 0; i < floats.size(); ++i) floats[i] = 1.f / (i + 1);
  float sum1 = std::accumulate(floats.begin(), floats.end(), 0.f);
  float sum2 = std::accumulate(floats.rbegin(), floats.rend(), 0.f);
  std::cout << (sum1 - sum2) << std::endl;

  //                   0  1  2  3  4  5  6  7  8
  std::vector<int> arr{1, 2, 3, 4, 4, 5, 5, 6, 7};

  for (int i = 0; i < arr.size(); ++i) util::debug("[{}]", i);
  util::debug("\n");
  for (const auto& it : arr) util::debug(" {} ", it);
  util::debug("\n");

  {
    int lower_bound = lowerBound(arr, 5);
    if (lower_bound >= 0)
      util::debug("lower: arr[{}] = {}\n", lower_bound, arr[lower_bound]);
  }
  {
    int upper_bound = upperBound(arr, 5);
    if (upper_bound >= 0)
      util::debug("upper: arr[{}] = {}\n", upper_bound, arr[upper_bound]);
  }

  return 0;
}
