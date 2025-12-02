#pragma once

#include <utility>

#include "Log.hpp"
#include "Scope.hpp"
namespace KasX::Compiler::Core {
class ActionScope : public Scope {
  explicit ActionScope(std::string name, Scope* parent) : Scope(std::move(name), SCOPE_TYPES::ACTION, parent) {
    CORE_TRACE("Function scope Initialized: {} parent: {}", getScopeName(), parent->getScopeName());
  }
};
}  // namespace KasX::Compiler::Core
