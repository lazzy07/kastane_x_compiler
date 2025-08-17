#pragma once
#include <kasx/Types.hpp>

#include "../visitors/ProgramVisitor.hpp"

namespace KasX::Compiler::Core {
class Domain {
 public:
  explicit Domain(DomainData &data);
  ~Domain();

 private:
  std::unique_ptr<DomainData> m_DomainData;
  std::unique_ptr<KasX::Compiler::Visitor::ProgramVisitor> m_ProgramVisitor;
};
}  // namespace KasX::Compiler::Core