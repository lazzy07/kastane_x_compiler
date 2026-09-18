/*
 * File name: TriggerDeclaration.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-03 23:31:22
 * Date modified: 2026-09-03 23:31:22
 * ------
 */

#pragma once

#include <memory>
#include <vector>

#include "kasx/core/scopes/Scope.hpp"
#include "kasx/data_structures/declarations/Declaration.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Grounded {
struct GroundedTrigger;
}
namespace KasX::Compiler::DataStructures::Declarations {
/**
 * @class TriggerDeclaration
 * @brief Declaration of a trigger (Scope for the trigger and access to the grounded triggers can be found here)
 *
 */
struct TriggerDeclaration : public Declaration {
  Core::Scopes::Scope* scope;                                                ///< Trigger scope
  std::vector<std::unique_ptr<Grounded::GroundedTrigger>> groundedTriggers;  ///< Grounded triggers created from the declaration

  TriggerDeclaration(const std::string& name, Debug::DomainFileTrace fileTrace)
      : Declaration(name, DECLARATION_TYPES::TRIGGER_DECL, fileTrace) {}
};
}  // namespace KasX::Compiler::DataStructures::Declarations
