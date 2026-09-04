/*
 * File name: FunctionDeclaration.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-03 13:44:13
 * Date modified: 2026-09-03 13:44:13
 * ------
 */

#pragma once

#include <memory>
#include <vector>

#include "kasx/core/scopes/Scope.hpp"
#include "kasx/data_structures/declarations/Declaration.hpp"

namespace KasX::Compiler::DataStructures::Grounded {
struct GroundedAction;
}

namespace KasX::Compiler::DataStructures::Declarations {
/**
 * @class ActionDeclaration
 * @brief Declaration of an action (Scope for the actiona and access to the gronded functions can be found here)
 *
 */
struct ActionDeclaration : public Declaration {
  Core::Scopes::Scope* scope;                                               ///< Action scope
  std::vector<std::unique_ptr<Grounded::GroundedAction*>> groundedActions;  ///< Grounded functions created from the declaration
};
}  // namespace KasX::Compiler::DataStructures::Declarations
