#include "controller.h"

#include <iostream>

#include "service.h"

namespace pimpl {
class Controller::ControllerImpl {
 public:
  Service service;
  void process(int data) const { service.process(data); }
};

Controller::Controller(const Service& service)
    : pimpl_(std::make_unique<ControllerImpl>(service)) {
  std::cout << "[Controller]:... ctor!\n";
}

GENERATE_RULE5_DEFENITION(Controller)

void Controller::process(int data) const {
  std::cout << "[Controller]:... processing: " << data << std::endl;
  pimpl_->process(data);
}

}  // namespace pimpl
