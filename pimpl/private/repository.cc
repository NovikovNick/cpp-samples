#include "repository.h"

#include <iostream>

namespace pimpl {
class Repository::RepositoryImpl {
 public:
  int process(int data) const { return data + 1; }
};

Repository::Repository([[maybe_unused]] const int id)
    : pimpl_(std::make_unique<RepositoryImpl>()) {
  std::cout << "[Repository]:... ctor!\n";
}

GENERATE_RULE5_DEFENITION(Repository)

void Repository::process(int data) const {
  std::cout << "[Controller]:... answer is "  //
            << pimpl_->process(data)          //
            << std::endl;
}

}  // namespace pimpl
