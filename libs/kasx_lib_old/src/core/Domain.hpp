#pragma once
#include <kasx/Types.hpp>
#include <memory>

#include "../visitors/ProgramVisitor.hpp"
#include "ActionScope.hpp"
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

  /**
   * @brief This function will generate a new ActionScope and assign it as the current scope.
   *
   * Action scope created by this function will be the current scope that new Entities and Expression assigned to.
   *
   * @param name Name of the scope, usually the action name
   * @return The action scope
   */
  ActionScope* createActionScope(std::string name);
  void resetScope();  //< Reset the current scope back to GlobalScope

 private:
  // Meta-data that the domain is initialized with
  DomainData m_DomainData;
  // Program visitor for the domain
  std::unique_ptr<KasX::Compiler::Visitor::ProgramVisitor> m_ProgramVisitor;

  // Global Scope
  KasX::Compiler::Core::GlobalScope m_GlobalScope;
  KasX::Compiler::Core::Scope* m_CurrentScope;  // Yes, this is not an error! Im using raw pointers here.
};
}  // namespace KasX::Compiler::Core
