/*
* File name: DefaultScope.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-27 12:32:41
// Date modified: 2025-12-27 13:51:12
* ------
*/

#include "GlobalScope.hpp"

#include "Log.hpp"

namespace KasX::Compiler::Core::Scopes {
GlobalScope::GlobalScope() { CORE_TRACE("DefaultScope: Initialized"); }

GlobalScope::~GlobalScope() { CORE_TRACE("DefaultScope: Terminated"); }

}  // namespace KasX::Compiler::Core::Scopes
