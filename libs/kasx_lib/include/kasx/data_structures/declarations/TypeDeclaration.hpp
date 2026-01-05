/*
* File name: TypeDeclaration.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 12:34:31
// Date modified: 2026-01-04 19:43:16
* ------
*/
#pragma once

#include <vector>

#include "Declaration.hpp"
#include "EntityDeclaration.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
struct TypeDeclaration : public Declaration {
  std::vector<TypeDeclaration*> parents;     ///< Parent type declaration of the current type.
  std::vector<TypeDeclaration*> children;    ///< Children types of this type.
  std::vector<EntityDeclaration*> entities;  ///< Entities created using this type.

  /**
   * @brief Constructor function of the TypeDeclaration
   *
   * @param name Name of the type declaration.
   */
  TypeDeclaration(const std::string& name, const std::vector<TypeDeclaration*>& parents, Debug::DomainFileTrace fileTrace,
                  Declaration::MUTABILITY mutability);

  /**
   * @brief Add a new entity under this type declaration.
   *
   * @param entity Entity with the current type.
   */
  void addNewEntityDeclaration(EntityDeclaration* entity);

  /**
   * @brief Add a child type to this type.
   *
   * @param child Child type of this current type.
   */
  void addChildType(TypeDeclaration* child);
};
}  // namespace KasX::Compiler::DataStructures::Declarations
