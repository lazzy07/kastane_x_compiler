/*
* File name: TypeDeclaration.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 12:34:31
// Date modified: 2025-12-15 22:30:44
* ------
*/
#pragma once

#include <vector>

#include "Declaration.hpp"
#include "EntityDeclaration.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
struct TypeDeclaration : public Declaration {
  TypeDeclaration* parent;                   ///< Parent type declaration of the current type.
  std::vector<TypeDeclaration*> children;    ///< Children types of this type.
  std::vector<EntityDeclaration*> entities;  ///< Entities created using this type.

  /**
   * @brief Constructor function of the TypeDeclaration
   *
   * @param name Name of the type declaration.
   */
  explicit TypeDeclaration(std::string name);

  /**
   * @brief Add a new entity under this type declaration.
   *
   * @param entity Entity with the current type.
   */
  void addNewEntityDeclaration(EntityDeclaration* entity);

  /**
   * @brief Add a parent that this type is inherited from.
   *
   * @param parent Parent type of the current type.
   */
  void addParent(TypeDeclaration* parent) { this->parent = parent; };

  /**
   * @brief Add a child type to this type.
   *
   * @param child Child type of this current type.
   */
  void addChildType(TypeDeclaration child);
};
}  // namespace KasX::Compiler::DataStructures::Declarations
