#pragma once

#include <memory>
#include <vector>

#include "../../core/ActionScope.hpp"
#include "../expressions/Expression.hpp"
#include "Declaration.hpp"

namespace KasX::Compiler::DataStructures {
struct ActionDecl : Declaration {
  std::unique_ptr<Expression> preconditions;  /// Preconditions of the action as an expression
  std::unique_ptr<Expression> effects;        /// Effects expression
  std::vector<Declaration> consenting;        /// List of consenting characters
  std::unique_ptr<Expression> observing;      /// Observing characters
  Core::ActionScope* scope;                   /// Scope of the action belongs to.
};
}  // namespace KasX::Compiler::DataStructures
