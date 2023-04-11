#define DEBUG 1;

#include "stun/stun_client.h"
#include "util/log.h"

int main(int argc, char argv[]) {
  std::thread([] {
    try {
      stun::StunClient client("64.233.163.127", 19302);  // stun.l.google.com
      client.sendRequest();

    } catch (const stun::ConnectionException& e) {
      util::debug("ConnectionException: {}\n", e.what());
    } catch (const stun::UnableToReceiveException& e) {
      util::debug("UnableToReceiveException: {}\n", e.what());
    } catch (...) {
      util::debug("Unknown error\n");
    }
  }).detach();

  using namespace std::chrono_literals;
  std::this_thread::sleep_for(2s);

  return 0;
}
