#ifndef LEETCODE_SNAPSHOT_ARRAY_H
#define LEETCODE_SNAPSHOT_ARRAY_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class SnapshotArray {
  struct Snapshot {
    int snap = -1;
    int val = 0;
  };

  int currentSnap;
  std::unordered_map<int, std::vector<Snapshot>> data;

 public:
  SnapshotArray(int length) : currentSnap(0) {}

  void set(int index, int val) {
    auto& snapshots = data[index];
    if (snapshots.empty()) {
      snapshots.push_back({currentSnap, val});
      debug("create new val {} at index {}\n", val, index);
    } else {
      auto& head = snapshots[snapshots.size() - 1];
      if (head.snap == currentSnap) {
        head.val = val;
        debug("override val {} at index {}\n", val, index);
      } else {
        snapshots.push_back({currentSnap, val});
        debug("add new val {} at index {}\n", val, index);
      }
    }
  }

  int snap() { return currentSnap++; }

  int get(int index, int snap_id) {
    auto& snapshots = data[index];
    if (snapshots.empty()) return 0;

    auto it =
        std::upper_bound(snapshots.begin(), snapshots.end(), snap_id, predicate);
    return it == snapshots.end() ? snapshots[snapshots.size() - 1].val : (*it).val;
  }

  static bool predicate(const int& snap_id, const Snapshot& rhs) {
    return snap_id < rhs.snap;
  }
};

}  // namespace leetcode
#endif  // LEETCODE_SNAPSHOT_ARRAY_H
