#ifndef SAMPLE_PIMPL_REPOSITORY_H
#define SAMPLE_PIMPL_REPOSITORY_H

#include <memory>

#include "util_macros.h"

namespace pimpl {

class Repository final {
 public:
  Repository(int id);

  void process(int data) const;

  GENERATE_RULE5_DECLARATION(Repository)

 private:
  class RepositoryImpl;
  std::shared_ptr<RepositoryImpl> pimpl_;
};
}  // namespace pimpl

#endif  // SAMPLE_PIMPL_REPOSITORY_H
