/*
* File name: TypeDeclaration.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 13:52:44
// Date modified: 2026-01-09 23:04:07
* ------
*/

#include <kasx/data_structures/declarations/TypeDeclaration.hpp>
#include <vector>

#include "Log.hpp"
#include "kasx/data_structures/declarations/Declaration.hpp"
#include "kasx/data_structures/declarations/EntityDeclaration.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
TypeDeclaration::TypeDeclaration(const std::string& name, const std::vector<TypeDeclaration*>& parents,
                                 Debug::DomainFileTrace trace, Declaration::MUTABILITY mutability)
    : Declaration(name, DECLARATION_TYPES::TYPE_DECL, trace, mutability), parents(parents) {
  CLI_TRACE("Type declaration added: {}", this->name);
}

void TypeDeclaration::addNewEntityDeclaration(EntityDeclaration* entity) {
  this->entities.emplace_back(entity);
  CLI_TRACE("New entity : {} added to the type: {}", entity->name, this->name);
}

void TypeDeclaration::addChildType(TypeDeclaration* child) {
  this->children.emplace_back(child);
  CLI_TRACE("Child type declaration {} added to the type: {}", child->name, this->name);
}
}  // namespace KasX::Compiler::DataStructures::Declarations
