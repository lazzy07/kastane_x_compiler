/*
* File name: Scope.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-28 12:14:46
// Date modified: 2025-12-30 22:08:32
* ------
*/
#include <Log.hpp>
#include <kasx/core/scopes/Scope.hpp>

namespace KasX::Compiler::Core::Scopes {
Scope::Scope(std::string name, SCOPE_TYPES type) : m_Type(type), m_Name(std::move(name)) {
  CORE_TRACE("Scope Initialized: {}", m_Name);
};

Scope::~Scope() { CORE_TRACE("Scope {} Terminated", m_Name); }
}  // namespace KasX::Compiler::Core::Scopes
