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

namespace KasX::Compiler::DataStructures::Grounded {
struct GroundedTrigger;
}
namespace KasX::Compiler::DataStructures::Declarations {
struct TriggerDeclaration {
  Core::Scopes::Scope* scope;
  std::vector<std::unique_ptr<Grounded::GroundedTrigger>> groundedTriggers;
};
}  // namespace KasX::Compiler::DataStructures::Declarations
