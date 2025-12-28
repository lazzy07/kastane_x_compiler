/*
* File name: DefaultScope.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-27 11:39:34
// Date modified: 2025-12-28 14:53:35
* ------
*/

#include <kasx/data_structures/declarations/TypeDeclaration.hpp>
#include <kasx/debug/DomainFileTrace.hpp>
#include <memory>
#include <unordered_map>

#include "Scope.hpp"
#include "kasx/data_structures/declarations/EntityDeclaration.hpp"

namespace KasX::Compiler::Core::Scopes {
/**
 * @class GlobalScope
 * @brief Global Scopes keeps track of all the actions, entities, triggers and type data. It is like the entrypoint to all the
 * stuff in the domain.
 *
 */
class GlobalScope : public Scope {
 public:
  /**
   * @brief Constructor of the Global scope.
   */
  GlobalScope();
  /**
   * @brief Destructor of the Global scope.
   */
  ~GlobalScope();

  /**
   * @brief Add a new type declaration.
   *
   * @param typeDeclaration Type declaration that needs to be added.
   */
  void addTypeDeclaration(DataStructures::Declarations::TypeDeclaration* typeDeclaration,
                          KasX::Compiler::Debug::DomainFileTrace* trace);

  /**
   * @brief Move a type declaration, can be used when, parent changes
   *
   * @example When user defines entity is also a type of item, `type Entity : Item;`
   *
   * @param name Name of the type declaration that needs to be moved.
   */
  void moveTypeDeclaration(const std::string& name, DataStructures::Declarations::TypeDeclaration* parentDeclaration);
  /**
   * @brief Add a new child scope to the global scope
   *
   * @param scope New scope as a unique pointer.
   */
  void addChildScope(std::unique_ptr<Scope> scope) { m_ChildrenScopes.emplace_back(std::move(scope)); };

  /**
   * @brief Get type declaration from the global scope.
   *
   * @param name name of the type delclaration.
   * @return DataStructures::Declarations::TypeDeclaration or nullptr
   */
  DataStructures::Declarations::TypeDeclaration* getTypeDeclaration(const std::string& name) const {
    return m_TypeDeclarations.find(name)->second;
  };

  /**
   * @brief Get entity declaration from the global scope.
   *
   * @param name Name of the requested entity declaration.
   * @return DataStructures::Declarations::EntityDeclaration if found or nullptr
   */
  DataStructures::Declarations::EntityDeclaration* getEntityDeclaration(const std::string& name) const {
    return m_EntityDeclarations.find(name)->second;
  }

 private:
  std::vector<std::unique_ptr<Scope>> m_ChildrenScopes;

  std::unordered_map<std::string, DataStructures::Declarations::TypeDeclaration*> m_TypeDeclarations;
  std::unordered_map<std::string, DataStructures::Declarations::EntityDeclaration*> m_EntityDeclarations;
};
}  // namespace KasX::Compiler::Core::Scopes
