/*
* File name: EntityDeclaration.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 16:46:52
// Date modified: 2026-01-05 01:46:51
* ------
*/
#pragma once

#include <vector>

#include "Declaration.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
class TypeDeclaration;
/**
 * @class EntityDeclaration
 * @brief Entities in the domain and relatedb data to that entity.
 */
struct EntityDeclaration : public Declaration {
  std::vector<Declarations::TypeDeclaration*> types;

  /**
   * @brief Entity declaration struct constructor.
   *
   * @param name Name of the entity declaration
   * @param types Type or the types of the entity declaration.
   * @param trace Debug trace of the declaration.
   */
  EntityDeclaration(const std::string& name, const std::vector<TypeDeclaration*>& types, Debug::DomainFileTrace trace)
      : Declaration(name, DECLARATION_TYPES::ENTITY_DECL, trace), types(types) {

        };
};
}  // namespace KasX::Compiler::DataStructures::Declarations
