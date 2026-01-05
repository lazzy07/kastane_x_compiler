/*
* File name: DefaultScope.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-27 11:39:34
// Date modified: 2026-01-05 01:52:39
* ------
*/

#include <kasx/data_structures/declarations/TypeDeclaration.hpp>
#include <kasx/debug/DomainFileTrace.hpp>
#include <memory>
#include <unordered_map>
#include <vector>

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
   * @brief Create a new type declaration in the global scope.
   *
   * @param name Name of the type.
   * @param parents Parents of the type that needs to be added.
   * @param trace File trace that keeps track of where the type exists in the domain file.
   */
  void createTypeDeclaration(const std::string& name, const std::vector<std::string>& parents,
                             const Debug::DomainFileTrace& trace,
                             DataStructures::Declarations::TypeDeclaration::MUTABILITY mutablity =
                                 DataStructures::Declarations::Declaration::MUTABILITY::IMMUTABLE);

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
    auto iter = m_TypeDeclarations.find(name);
    if (iter == m_TypeDeclarations.end()) return nullptr;
    return iter->second.get();
  };

  /**
   * @brief Get entity declaration from the global scope.
   *
   * @param name Name of the requested entity declaration.
   * @return DataStructures::Declarations::EntityDeclaration if found or nullptr
   */
  DataStructures::Declarations::EntityDeclaration* getEntityDeclaration(const std::string& name) const {
    auto iter = m_EntityDeclarations.find(name);
    if (iter == m_EntityDeclarations.end()) return nullptr;
    return iter->second.get();
  }

  /**
   * @brief Create a new entity declaration in global scope
   *
   * @param name Name of the entity
   * @param types Type of the entity
   * @param trace Debug file trace data to keep track of the domain file.
   */
  void createEntityDeclaration(const std::string& name, const std::vector<std::string>& types,
                               const Debug::DomainFileTrace& trace);

 private:
  std::vector<std::unique_ptr<Scope>> m_ChildrenScopes;

  std::unordered_map<std::string, std::unique_ptr<DataStructures::Declarations::TypeDeclaration>> m_TypeDeclarations;
  std::unordered_map<std::string, std::unique_ptr<DataStructures::Declarations::EntityDeclaration>> m_EntityDeclarations;

  bool allParentTypesExists(const std::vector<std::string>& parents) const;
  std::vector<DataStructures::Declarations::TypeDeclaration*> getAllParentDeclarations(
      const std::vector<std::string>& parentNames) const;
};
}  // namespace KasX::Compiler::Core::Scopes
