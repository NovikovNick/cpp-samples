#include "service.h"

#include <iostream>

#include "repository.h"

namespace pimpl {
class Service::ServiceImpl {
 public:
  Repository repository;
  void process(int data) const { repository.process(data + 1); }
};

Service::Service(const Repository& repository)
    : pimpl_(std::make_unique<ServiceImpl>(repository)) {
  std::cout << "[Service]:... ctor!\n";
}

GENERATE_RULE5_DEFENITION(Service)

void Service::process(int data) const {
  std::cout << "[Service]:... processing: " << data << std::endl;
  pimpl_->process(data);
}

}  // namespace pimpl
