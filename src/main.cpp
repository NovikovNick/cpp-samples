#define DEBUG 1;

#include "socket/udp_client.cc"
#include "socket/udp_server.cc"
#include "util/log.h"

int main(int argc, char argv[]) {

  std::thread([] {
    try {
      udp::server(7000);
    } catch (...) {
      util::debug("[SERVER]: Unknown error\n");
    }
  }).detach();

  std::thread([] {
    try {
      udp::UdpClient client("127.0.0.1", 7000);
      client.send("it works");
    } catch (const udp::ConnectionException& e) {
      util::debug("[CLIENT]: {}\n", e.what());
    } catch (...) {
      util::debug("[CLIENT]: Unknown error\n");
    }
  }).detach();

  using namespace std::chrono_literals;
  std::this_thread::sleep_for(2s);

  return 0;
}
