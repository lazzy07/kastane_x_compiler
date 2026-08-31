/*
* File name: Scope.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-28 12:14:46
// Date modified: 2026-08-29 22:12:17
* ------
*/
#include <Log.hpp>
#include <kasx/core/scopes/Scope.hpp>

namespace KasX::Compiler::Core::Scopes {
Scope::Scope(std::string name, SCOPE_TYPES type, Scope* parent) : m_Type(type), m_Name(std::move(name)), m_Parent(parent) {
  CORE_TRACE("Scope Initialized: {}", m_Name);
};

Scope::~Scope() { CORE_TRACE("Scope {} Terminated", m_Name); }

}  // namespace KasX::Compiler::Core::Scopes
