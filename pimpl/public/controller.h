#ifndef SAMPLE_PIMPL_CONTROLLER_H
#define SAMPLE_PIMPL_CONTROLLER_H

#include <memory>

#include "util_macros.h"

namespace pimpl {

class Service;

class Controller final {
 public:
  Controller(const Service& service);

  void process(int data) const;

  GENERATE_RULE5_DECLARATION(Controller)

 private:
  class ControllerImpl;
  std::shared_ptr<ControllerImpl> pimpl_;
};
}  // namespace pimpl

#endif  // SAMPLE_PIMPL_Y_H
