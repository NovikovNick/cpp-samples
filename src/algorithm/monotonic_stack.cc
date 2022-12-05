#include "../util/log.h"

namespace {
std::string toString(const std::vector<int>& arr, std::stack<int> stack) {
  std::string res;
  while (!stack.empty()) {
    int index = stack.top(), val = arr[index];
    res += std::format("{:3d}[{:2d}] ", val, index);
    stack.pop();
  }
  return res;
}

std::string toString(const int prv, const int mid, const int nxt,
                     const std::vector<int>& arr) {
  std::string res;
  if (prv == -1) res += "|";
  for (int i = 0; i < arr.size(); ++i) {
    if (nxt == i) res += "|";
    res +=
        mid == i ? std::format("{:3d}*", arr[i]) : std::format("{:3d}", arr[i]);
    if (prv == i) res += "|";
  }
  if (nxt == arr.size()) res += "|";
  return res;
}
}

void monotonicStack() {
  std::vector<int> arr{2, 4, 8, 5, 7, 1, 0, 6, 3};

  std::cout << "Monotonic stack for input: " << std::endl;
  for (const auto& it : arr) std::cout << it << " ";
  std::cout << std::endl;

  // monotonic asc stack;

  std::stack<int> stack;
  for (int i = 0, n = arr.size(); i <= n; ++i) {
    while (!stack.empty() && (i == n || arr[i] <= arr[stack.top()])) {
      int mid = stack.top();
      stack.pop();
      int nxt = i;
      int prv = stack.empty() ? -1 : stack.top();
      util::debug("-[{:2d}] ={:3d}. {}      stack:{}\n", mid, arr[mid],
                  toString(prv, mid, nxt, arr), toString(arr, stack));
    }
    stack.push(i);
    if (i != n)
      util::debug(
          "+[{:2d}] ={:3d}.                                     stack:{}\n", i,
          arr[i], toString(arr, stack));
  }
}