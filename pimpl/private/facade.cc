#include "facade.h"

#include <iostream>

#include "controller.h"
#include "repository.h"
#include "service.h"

namespace pimpl {
class Facade::FacadeImpl {
  Controller controller;

 public:
  FacadeImpl() : controller(Controller(Service{Repository{2}})) {}

  void dispatch(std::string_view address, int data) {
    if (!address.empty()) {
      controller.process(data);
    }
  }
};

Facade::Facade() : pimpl_(std::make_unique<FacadeImpl>()) {
  std::cout << "[Facade]:... ctor!\n";
}

Facade::~Facade() = default;

Facade::Facade(Facade&& x) = default;
Facade& Facade::operator=(Facade&& other) = default;

void Facade::processRequest(std::string_view address, int data) const {
  std::cout << "[Facade]:... start processing: " << address << std::endl;
  pimpl_->dispatch(address, data);
}

}  // namespace pimpl
