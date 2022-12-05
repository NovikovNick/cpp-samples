#include "../util/log.h"

int binarySearch(std::vector<int>& arr, int low, int high, int val) {
  int res = -1;
  util::debug(" low  mid high\n");
  while (low <= high) {
    int mid = low + (high - low) / 2;
    util::debug("{:4d} {:4d} {:4d} ", low, mid, high);
    if (arr[mid] >= val) {
      util::debug(" left\n");
      high = mid - 1;
      res = mid;  // upper bound
    } else {
      util::debug(" right\n");
      low = mid + 1;
      // lower bound res = mid;
    }
  }
  return res;
};