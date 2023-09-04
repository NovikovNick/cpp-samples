#ifndef SAMPLE_PIMPL_FACADE_H
#define SAMPLE_PIMPL_FACADE_H

#include <memory>
#include <string_view>

namespace pimpl {

class Facade final {
 public:
  Facade();

  ~Facade();
  Facade(Facade&& other);
  Facade& operator=(Facade&& other);

  Facade(const Facade& other) = delete;
  Facade& operator=(const Facade& other) = delete;

  void processRequest(std::string_view address, int data) const;

 private:
  class FacadeImpl;
  std::unique_ptr<FacadeImpl> pimpl_;
};
}  // namespace pimpl

#endif  // SAMPLE_PIMPL_FACADE_H
