#ifndef LEETCODE_ONLINE_STOCK_SPAN_H
#define LEETCODE_ONLINE_STOCK_SPAN_H
#include <algorithm>
#include <deque>
#include <format>
#include <iostream>
#include <stack>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class StockSpanner {
  std::deque<std::stack<int>> stocks;

 public:
  StockSpanner() : stocks(std::deque<std::stack<int>>{{}}) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }

  int next(int price) {
    if (stocks.front().empty()) {
      stocks.front().push(price);
      return 1;
    }

    if (stocks.front().top() > price) {
      stocks.push_front({});
      stocks.front().push(price);
      return 1;
    } else {
      stocks.front().push(price);

      int res = 0;
      for (const auto& stock : stocks) {
        if (stock.top() <= price) {
          res += stock.size();
        } else {
          break;
        }
      }
      return res;
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ONLINE_STOCK_SPAN_H
