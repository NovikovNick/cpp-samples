#include "../util/log.h"


/*
  //
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
*/

int lowerBound(std::vector<int>& arr, int val) {
  int low = 0, mid, high = arr.size() - 1;
  util::debug(" low  mid high\n");
  while (low <= high) {
    mid = low + (high - low) / 2;
    util::debug("{:4d} {:4d} {:4d} ", low, mid, high);
    if (arr[mid] >= val) {
      util::debug(" left\n");
      high = mid - 1;
    } else {
      util::debug(" right\n");
      low = mid + 1;
    }
  }
  return low;
};

int upperBound(std::vector<int>& arr, int val) {
  int low = 0, mid, high = arr.size() - 1;
  util::debug(" low  mid high\n");
  while (low <= high) {
    mid = low + (high - low) / 2;
    util::debug("{:4d} {:4d} {:4d} ", low, mid, high);
    if (arr[mid] > val) {
      high = mid - 1;
      util::debug(" left\n");
    } else {
      util::debug(" right\n");
      low = mid + 1;
    }
  }
  return low;
};
