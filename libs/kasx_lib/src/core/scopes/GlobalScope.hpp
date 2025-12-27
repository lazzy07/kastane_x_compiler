/*
* File name: DefaultScope.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-27 11:39:34
// Date modified: 2025-12-27 14:31:43
* ------
*/

#include "Scope.hpp"
#include "kasx/data_structures/declarations/TypeDeclaration.hpp"

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
  void addTypeDeclaration(DataStructures::Declarations::TypeDeclaration* typeDeclaration);

  /**
   * @brief Move a type declaration, can be used when, parent changes
   *
   * @example When user defines entity is also a type of item, `type Entity : Item;`
   *
   * @param name Name of the type declaration that needs to be moved.
   */
  void moveTypeDeclaration(const std::string& name, DataStructures::Declarations::TypeDeclaration* parentDeclaration);
};
}  // namespace KasX::Compiler::Core::Scopes
