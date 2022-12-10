#define DEBUG 1

#include <format>
#include <iostream>
#include <stack>
#include <vector>

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
*/
int main(int argc, char* argv[]) {
  /*try {

    if (argc < 3) {
      tcp::server(argv[1]);
    } else {
      tcp::client(argv[1], argv[2]);
    }

  } catch (std::runtime_error const& e) {
    util::debug("Runtime err: {}\n", e.what());
  } catch (...) {
    util::debug("Unexpected error\n");
  }*/

  try {

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
  }
}
