/*
* File name: DefaultScope.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-27 12:32:41
// Date modified: 2025-12-28 14:43:22
* ------
*/

#include "GlobalScope.hpp"

#include "Log.hpp"

namespace KasX::Compiler::Core::Scopes {
GlobalScope::GlobalScope() : Scope("Global Scope", SCOPE_TYPES::GLOBAL) { CORE_TRACE("Global Scope: Initialized"); }

GlobalScope::~GlobalScope() { CORE_TRACE("Global Scope: Terminated"); }

}  // namespace KasX::Compiler::Core::Scopes
