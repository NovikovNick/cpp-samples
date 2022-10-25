#include <algorithm>
#include <bit>
#include <bitset>
#include <deque>
#include <format>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Node {
  int x_;
  int y_;

 public:
  Node(int x, int y) : x_(x), y_(y) {}

  int GetX() const { return x_; }
  int GetY() const { return y_; }
  std::string ToString() const {
    return std::format("[{:2d},{:2d}]", GetX(), GetY());
  }
};

class NodePath {
 private:
  Node start_;
  Node end_;

  Node head_;
  std::deque<Node> path_;
  float distanceFromStart_;
  float distanceToEnd_;

  float getDistance(const Node& n1, const Node& n2) const {
    auto [x0, x1] = std::minmax(n1.GetX(), n2.GetX());
    auto [y0, y1] = std::minmax(n1.GetY(), n2.GetY());
    return std::sqrt(std::pow(x1 - x0, 2) + std::pow(y1 - y0, 2));
  }

 public:
  NodePath(const Node& start, const Node& end)
      : start_(start),
        head_(start),
        end_(end),
        distanceFromStart_(0.0),
        distanceToEnd_(getDistance(head_, end_)){};

  void AddNode(const Node& node) {
    distanceFromStart_ = getDistance(start_, node);
    distanceToEnd_ = getDistance(end_, node);
    path_.push_back(node);

    std::cout << std::format("from start - {:2.1f}, to end - {:2.1f}",
                             distanceFromStart_, distanceToEnd_)
              << std::endl;
    head_ = node;
  };
  float GetDistanceFromStart() const { return distanceFromStart_; };
  float GetDistanceToEnd() const { return distanceToEnd_; };
  std::string ToString() const {
    auto res = "head: " + head_.ToString();

    res += std::format(" from start - {:2.1f}, to end - {:2.1f} ",
                       distanceFromStart_, distanceToEnd_);
    res += "{ ";
    for (auto it : path_) {
      res += " " + it.ToString();
    }
    res += "}";
    return res;
  }
};

int main() {
  std::cout << "it works..." << std::endl;

  Node start(-1, -1);
  Node end(4, 4);

  auto comp = [](const NodePath& p1, const NodePath& p2) -> bool {
    float distToEnd1 = p1.GetDistanceToEnd();
    float distToEnd2 = p2.GetDistanceToEnd();
    if (distToEnd1 == distToEnd2) {
      return p1.GetDistanceFromStart() > p2.GetDistanceFromStart();
    } else {
      return distToEnd1 > distToEnd2;
    }
  };

  std::priority_queue<NodePath, std::vector<NodePath>, decltype(comp)> queue(
      comp);

  for (auto it : {1, 2, 3, 4}) {
    NodePath path(start, end);
    path.AddNode(Node(0, it + 1));
    path.AddNode(Node(0, it + 2));
    path.AddNode(Node(4, it + 3));
    queue.push(path);
  }

  while (!queue.empty()) {
    std::cout << queue.top().ToString() << std::endl;
    queue.pop();
  }

  auto hashcode = [](const Node& n) {
    auto hash1 = std::hash<int>{}(n.GetX());
    auto hash2 = std::hash<int>{}(n.GetY());
    if (hash1 != hash2) {
      return hash1 ^ hash2;
    }
    return hash1;
  };
  auto equal = [](const Node& n1, const Node& n2) {
    return ((n1.GetX() == n2.GetX()) && (n1.GetY() == n2.GetY()));
  };
  std::unordered_set<Node, decltype(hashcode), decltype(equal)> set(32, hashcode, equal);
  for (int x = 0; x < 3; ++x) {
    for (int y = 0; y < 3; ++y) {
      set.insert({x, y});
    }
  }

  for (auto it : set) {
    std::cout << it.ToString() << std::endl;
  }
}
