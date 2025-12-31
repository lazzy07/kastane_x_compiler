/*
* File name: TypeDeclaration.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 13:52:44
// Date modified: 2025-12-30 19:03:34
* ------
*/

#include <kasx/data_structures/declarations/TypeDeclaration.hpp>
#include <utility>
#include <vector>

#include "Log.hpp"
#include "kasx/data_structures/declarations/Declaration.hpp"
#include "kasx/data_structures/declarations/EntityDeclaration.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
TypeDeclaration::TypeDeclaration(std::string name, std::vector<TypeDeclaration*> parents, Debug::DomainFileTrace trace)
    : Declaration(std::move(name), DECLARATION_TYPES::TYPE_DECL, trace), parents(std::move(parents)) {
  CLI_TRACE("New type declaration added: {}", name);
}

void TypeDeclaration::addNewEntityDeclaration(const EntityDeclaration& entity) {
  this->entities.emplace_back(entity);
  CLI_TRACE("New entity : {} added to the type: {}", entity.name, this->name);
}

void TypeDeclaration::addChildType(const TypeDeclaration& child) {
  this->children.emplace_back(child);
  CLI_TRACE("Child type declaration {} added to the type: {}", child.name, this->name);
}
}  // namespace KasX::Compiler::DataStructures::Declarations
