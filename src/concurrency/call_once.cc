#include <thread>

#include "../util/log.h"

namespace concurrency {


/*
concurrency::SomeResource resource;
std::vector<std::thread> threads;
for (int i = 0; i < 10; ++i)
    threads.emplace_back( [&resource]() { util::debug("{}\n", resource.get()); });
for (auto& t : threads) t.join();
*/
class SomeResource {
  using R = std::string;
  R resource;
  std::once_flag resource_flag;

  void initResource() {
    util::debug("resource was initialized\n");
    resource = "it works...";
  }

 public:
  R get() {
    std::call_once(resource_flag, &SomeResource::initResource, this);
    return resource;
  }
};

}  // namespace concurrency
