#pragma once
#include <kasx/Types.hpp>

namespace KasX::Compiler::Core {
class Domain {
 public:
  Domain(DomainData &data);
  ~Domain();

 private:
  std::unique_ptr<DomainData> m_DomainData;
};
}  // namespace KasX::Compiler::Core