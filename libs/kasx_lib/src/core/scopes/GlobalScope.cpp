/*
* File name: DefaultScope.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-27 12:32:41
// Date modified: 2025-12-30 22:08:58
* ------
*/

#include <kasx/core/scopes/GlobalScope.hpp>

#include "Log.hpp"
#include "kasx/data_structures/declarations/TypeDeclaration.hpp"

namespace KasX::Compiler::Core::Scopes {
GlobalScope::GlobalScope() : Scope("Global Scope", SCOPE_TYPES::GLOBAL) { CORE_TRACE("Global Scope: Initialized"); }

GlobalScope::~GlobalScope() { CORE_TRACE("Global Scope: Terminated"); }

void GlobalScope::addTypeDeclaration(DataStructures::Declarations::TypeDeclaration* type, Debug::DomainFileTrace* trace) {}

}  // namespace KasX::Compiler::Core::Scopes
