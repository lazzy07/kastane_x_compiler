/*
 * File name: GroundedTrigger.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-03 23:57:32
 * Date modified: 2026-09-03 23:57:32
 * ------
 */

#pragma once

#include "kasx/Types.hpp"
#include "kasx/data_structures/declarations/TriggerDeclaration.hpp"
#include "kasx/data_structures/expressions/Expression.hpp"

namespace KasX::Compiler::DataStructures::Grounded {
struct GroundedTrigger {
  declaration_id id;                                                        ///< Grounded trigger ID
  Compiler::DataStructures::Declarations::TriggerDeclaration* declaration;  ///< Parent trigger declaration pointer

  Expressions::ExpressionPtr precondition;  ///< Precondition of the trigger
  Expressions::ExpressionPtr effect;        ///< Effect of the trigger
};
}  // namespace KasX::Compiler::DataStructures::Grounded
