#include <iostream>
#include <regex>
#include <string>

#include "stun/stun_client.h"

template <typename... Args>
void log(const std::string_view& str, Args&&... args) {
  std::cout << std::vformat(str, std::make_format_args(args...));
}

class ValidationException : public std::runtime_error {
 public:
  ValidationException(const std::string input)
      : std::runtime_error(std::format(
            "Illegal addres: {}. Should be like 127.0.0.1:80", input)) {}
};

void validateRemoteHostPort(const std::string& input);

int main(int argc, char argv[]) {
  std::string stun_host_str("64.233.163.127");  // stun.l.google.com
  uint16_t local_port = 7000, stun_port = 19302;

  /*
  log("Local port: ");
  std::cin >> local_port;

  log("Stun server host: ");
  std::cin >> stun_host_str;

  log("Stun server port: ");
  std::cin >> remote_port;
  */

  std::thread([&] {
    try {
      stun::StunClient client(local_port, stun_host_str.c_str(), stun_port);
      client.sendRequest();
      client.waitResponse();

      log("Remote host:port:");
      std::string input("127.0.0.1:7000");      
      std::cin >> input;
      validateRemoteHostPort(input);

      auto colon = input.find(':');
      std::string remote_host = input.substr(0, colon);
      uint16_t remote_port = std::stoi(input.substr(colon + 1));

      client.connect(remote_host.c_str(), remote_port);

    } catch (const ValidationException& e) {
      log("ValidationException: {}\n", e.what());

    } catch (const stun::ConnectionException& e) {
      log("ConnectionException: {}\n", e.what());

    } catch (const stun::UnableToSendException& e) {
      log("UnableToSendException: {}\n", e.what());

    } catch (const stun::UnableToReceiveException& e) {
      log("UnableToReceiveException: {}\n", e.what());

    } catch (...) {
      log("Unknown error\n");
    }
  }).detach();

  using namespace std::chrono_literals;
  std::this_thread::sleep_for(10min);

  return 0;
}


void validateRemoteHostPort(const std::string& input) {
  const std::regex regex(
      "^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9]"
      "[0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5]):[0-9]+$");
  if (!std::regex_match(input, regex)) {
    throw ValidationException(input);
  }
}