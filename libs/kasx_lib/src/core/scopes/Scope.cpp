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
#include <memory>

namespace KasX::Compiler::Core::Scopes {
Scope::Scope(std::string name, SCOPE_TYPES type, Scope* parent) : m_Type(type), m_Name(std::move(name)), m_Parent(parent) {
  CORE_TRACE("Scope Initialized: {}", m_Name);
};

Scope::~Scope() { CORE_TRACE("Scope {} Terminated", m_Name); }

std::string Scope::getReplaceString(const std::string& name) {
  auto foundName = m_ReplaceMap.find(name);

  if (foundName == nullptr) {
    return name;
  }

  return foundName->second;
}

void Scope::addIdentifierToReplace(const std::string& identifier, const std::string& replace) {
  if (!m_ReplaceMode) {
    CORE_ERROR("Current scope {} is not in replacement mode", m_Name);
    return;
  }
  m_ReplaceMap.emplace(std::pair<std::string, std::string>(identifier, replace));
}

void Scope::disableReplaceMode() {
  m_ReplaceMode = false;
  m_ReplaceMap = {};
}
void Scope::enableReplaceMode() {
  m_ReplaceMode = true;
  m_ReplaceMap = {};
}

Scope* Scope::createChildScope(const std::string& name, SCOPE_TYPES type) {
  m_ChildScopes.emplace(name, std::make_unique<Scope>(name, type, this));

  return m_ChildScopes.find(name)->second.get();
}
}  // namespace KasX::Compiler::Core::Scopes
