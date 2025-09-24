#pragma once
#include <kasx/Types.hpp>
#include <memory>

#include "../visitors/ProgramVisitor.hpp"
#include "Scope.hpp"

namespace KasX::Compiler::Core {
class Domain {
 public:
  explicit Domain(DomainData &data);
  ~Domain();

  void InitVisitor();
  void InitDefaultTypes();

  [[nodiscard]] inline KasX::Compiler::Core::Scope *GetCurrentScope() { return m_CurrentScope; };

 private:
  // Meta-Data that the domain initialized with
  DomainData m_DomainData;
  // Program visitor for the domain
  std::unique_ptr<KasX::Compiler::Visitor::ProgramVisitor> m_ProgramVisitor;

  // Global Scope
  KasX::Compiler::Core::Scope m_GlobalScope;
  KasX::Compiler::Core::Scope
      *m_CurrentScope;  // Yes, this is not an error! Im using raw pointers here.
};
}  // namespace KasX::Compiler::Core