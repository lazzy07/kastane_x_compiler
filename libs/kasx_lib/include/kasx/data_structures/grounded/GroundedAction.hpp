/*
 * File name: GroundedAction.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-03 17:33:39
 * Date modified: 2026-09-03 17:33:39
 * ------
 */
#pragma once

#include "kasx/Types.hpp"
#include "kasx/data_structures/declarations/ActionDeclaration.hpp"
#include "kasx/data_structures/declarations/EntityDeclaration.hpp"
#include "kasx/data_structures/expressions/Expression.hpp"
namespace KasX::Compiler::DataStructures::Grounded {
struct GroundedAction {
  declaration_id id;                                                       ///< Grounded actions ID
  Compiler::DataStructures::Declarations::ActionDeclaration* declaration;  ///< Parent action declaration pointer

  Expressions::ExpressionPtr precondition;  ///< Precondition of the action
  Expressions::ExpressionPtr effect;        ///< Effect of the action

  Declarations::EntityDeclaration* consenting;  ///< Consenting characters for this action
  Expressions::ExpressionPtr observation;       ///< Observation expressions
};
}  // namespace KasX::Compiler::DataStructures::Grounded
