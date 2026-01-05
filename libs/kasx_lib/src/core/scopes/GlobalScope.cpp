/*
* File name: DefaultScope.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-27 12:32:41
// Date modified: 2026-01-05 01:53:40
* ------
*/

#include <kasx/core/scopes/GlobalScope.hpp>
#include <memory>
#include <vector>

#include "Log.hpp"
#include "kasx/data_structures/declarations/Declaration.hpp"
#include "kasx/data_structures/declarations/TypeDeclaration.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::Core::Scopes {
GlobalScope::GlobalScope() : Scope("Global Scope", SCOPE_TYPES::GLOBAL) { CORE_TRACE("Global Scope: Initialized"); }

GlobalScope::~GlobalScope() { CORE_TRACE("Global Scope: Terminated"); }

void GlobalScope::createTypeDeclaration(const std::string& name, const std::vector<std::string>& parents,
                                        const Debug::DomainFileTrace& trace,
                                        DataStructures::Declarations::Declaration::MUTABILITY mutablity) {
  CLI_TRACE("Creating a new type declaration: {}", name);
  // Check if the type declaration already exists.
  const auto* typeDeclaration = this->getTypeDeclaration(name);

  if (typeDeclaration != nullptr) {
    CLI_TRACE("Type-Declaration with the same name: {} already exists", name);

    if (typeDeclaration->mutability == DataStructures::Declarations::Declaration::MUTABILITY::IMMUTABLE) {
      CLI_ERROR("Typle-Declaration '{}' is redifined and immutable, unable to modify!", name);
      return;
    }
  }

  // typeDeclaration does not already exists
  CLI_TRACE("A new Type-Declaration found in the domain: {}", name);

  // Check if all the parents already exits.
  bool parentTypesExists = this->allParentTypesExists(parents);

  if (!parentTypesExists) {
    CLI_ERROR("Unrecoverable error!, one or more parent types not found to declare the new type '{}'", name);
  }

  // All the parent types exists by this line.
  auto parentVector = this->getAllParentDeclarations(parents);

  // Create the type declaration with correct parents.
  auto newTypeDeclaration = std::make_unique<DataStructures::Declarations::TypeDeclaration>(name, parentVector, trace, mutablity);

  m_TypeDeclarations.emplace(name, std::move(newTypeDeclaration));

  for (const auto& parentType : parentVector) {
    parentType->addChildType(this->getTypeDeclaration(name));
  }
}

bool GlobalScope::allParentTypesExists(const std::vector<std::string>& parents) const {
  size_t foundParentSize = 0;

  for (const std::string& parentName : parents) {
    auto* parentType = this->getTypeDeclaration(parentName);

    if (parentType != nullptr) {
      CLI_TRACE("Parent type declaration found: '{}'", parentName);
      foundParentSize++;
    } else {
      CLI_ERROR("Parent type '{}' not found in the global scope", parentName);
    }
  }

  if (foundParentSize == parents.size()) {
    CLI_TRACE("All parents declared already exists");
    return true;
  }

  return false;
}

std::vector<DataStructures::Declarations::TypeDeclaration*> GlobalScope::getAllParentDeclarations(
    const std::vector<std::string>& parentNames) const {
  std::vector<DataStructures::Declarations::TypeDeclaration*> parentTypes;
  parentTypes.reserve(parentNames.size());

  for (const std::string& parentName : parentNames) {
    parentTypes.emplace_back(this->getTypeDeclaration(parentName));
  }

  return parentTypes;
};

void GlobalScope::createEntityDeclaration(const std::string& name, const std::vector<std::string>& types,
                                          const Debug::DomainFileTrace& trace) {
  const auto* existingEntityDecl = this->getEntityDeclaration(name);

  if (existingEntityDecl != nullptr) {
    CLI_ERROR("Entity declaration '{}' already exists", name);
    return;
  }

  // Check if all the types of the entity exists
  bool typesExists = this->allParentTypesExists(types);

  if (!typesExists) {
    CLI_ERROR("One or more types of the entity declaration '{}' does not exists!", name);
    return;
  }

  // All the types of the entity exists. Hence get all the type declarations.
  std::vector<DataStructures::Declarations::TypeDeclaration*> typeDeclarations = getAllParentDeclarations(types);

  m_EntityDeclarations.emplace(name,
                               std::make_unique<DataStructures::Declarations::EntityDeclaration>(name, typeDeclarations, trace));

  for (const auto& type : typeDeclarations) {
    type->addNewEntityDeclaration(this->getEntityDeclaration(name));
  }
}

}  // namespace KasX::Compiler::Core::Scopes
