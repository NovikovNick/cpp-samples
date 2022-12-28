#define DEBUG 1

#include <format>
#include <iostream>
#include <stack>
#include <vector>

#include "ggpo_samples.cc"
#include "socket/udp_client.cc"
#include "socket/udp_server.cc"
#include "util/log.h"

/*
1. backtracking: dfs and bfs
2. dp or update input array to avoid redundant calculation
3. monotonic stack. Track min/max elements
4. heap for max/min element for O(1)
5. binary search. Lower bound. Upper bound.
6. Union find - Ranks?
7. DP for finding common subsequence. Try to find DP formula in math notation

8. don't forget to use priority_queue<int> heap(piles.begin(), piles.end());
9. don't forget to use int totalSum = accumulate(piles.begin(), piles.end(), 0);
*/
int main(int argc, char *argv[]) {
  ggpo::GameAPI api;

  ggpo::Callbacks cb{0};
  cb.save_game_state = ggpo::saveGameState;
  cb.load_game_state = ggpo::loadGameState;

  ggpo::Launcher(cb).start();

  /*try {

    if (argc == 1) {
      udp::UdpClient udp(9999);
      udp.send("Does it work?");
    } else {
      std::string arg1 = argv[1];
      if (arg1 == "s") {
        udp::server(argv[1]);
      }
    }

  } catch (std::runtime_error const& e) {
    util::debug("Runtime err: {}\n", e.what());
  } catch (...) {
    util::debug("Unexpected error\n");
  }*/
  return 0;
}
