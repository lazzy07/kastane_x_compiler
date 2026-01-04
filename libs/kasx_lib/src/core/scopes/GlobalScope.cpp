/*
* File name: DefaultScope.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-27 12:32:41
// Date modified: 2026-01-01 15:52:44
* ------
*/

#include <kasx/core/scopes/GlobalScope.hpp>

#include "Log.hpp"
#include "kasx/data_structures/declarations/TypeDeclaration.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::Core::Scopes {
GlobalScope::GlobalScope() : Scope("Global Scope", SCOPE_TYPES::GLOBAL) { CORE_TRACE("Global Scope: Initialized"); }

GlobalScope::~GlobalScope() { CORE_TRACE("Global Scope: Terminated"); }

void GlobalScope::createTypeDeclaration(const std::string& name, const std::vector<std::string>& parents,
                                        const Debug::DomainFileTrace& trace) {
  CLI_TRACE("Creating a new type declaration");
  // Check if the type declaration already exists.

  // Check if all the parents already exits.
  for (const std::string& parentName : parents) {
    m_TypeDeclarations.find(parentName);
  }
}

}  // namespace KasX::Compiler::Core::Scopes
