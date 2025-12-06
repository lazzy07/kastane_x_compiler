#include "ActionScope.hpp"

KasX::Compiler::Core::ActionScope::ActionScope(std::string name, GlobalScope* parent)
    : Scope(std::move(name), SCOPE_TYPES::ACTION), m_GlobalScope(parent) {
  CORE_TRACE("Function scope Initialized: {}", getScopeName());
}

KasX::Compiler::Core::GlobalScope* KasX::Compiler::Core::ActionScope::getGlobalScope() { return m_GlobalScope; }
