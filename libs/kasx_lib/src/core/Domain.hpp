#pragma once
#include <kasx/Types.hpp>
#include <memory>

#include "../visitors/ProgramVisitor.hpp"
#include "GlobalScope.hpp"
#include "Scope.hpp"

namespace KasX::Compiler::Core {
class Domain {
 public:
  explicit Domain(DomainData& data);
  ~Domain();

  void initVisitor();
  void initDefaultTypes();

  [[nodiscard]] KasX::Compiler::Core::Scope* getCurrentScope() { return m_CurrentScope; };
  [[nodiscard]] KasX::Compiler::Core::GlobalScope* getGlobalScope() { return &m_GlobalScope; };

 private:
  // Meta-Data that the domain initialized with
  DomainData m_DomainData;
  // Program visitor for the domain
  std::unique_ptr<KasX::Compiler::Visitor::ProgramVisitor> m_ProgramVisitor;

  // Global Scope
  KasX::Compiler::Core::GlobalScope m_GlobalScope;
  KasX::Compiler::Core::Scope* m_CurrentScope;  // Yes, this is not an error! Im using raw pointers here.
};
}  // namespace KasX::Compiler::Core
