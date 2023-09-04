#ifndef SAMPLE_PIMPL_SERVICE_H
#define SAMPLE_PIMPL_SERVICE_H

#include <memory>

#include "util_macros.h"

namespace pimpl {

class Repository;

class Service final {
 public:
  Service(const Repository& repository);

  void process(int data) const;

  GENERATE_RULE5_DECLARATION(Service)

 private:
  class ServiceImpl;
  std::shared_ptr<ServiceImpl> pimpl_;
};
}  // namespace pimpl

#endif  // SAMPLE_PIMPL_SERVICE_H
