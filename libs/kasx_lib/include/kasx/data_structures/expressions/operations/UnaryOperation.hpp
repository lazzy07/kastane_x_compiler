/*
* File name: UnaryOperation.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-08-18 23:40:48
// Date modified: 2026-08-19 14:18:43
* ------
*/

#pragma once

#include <utility>

#include "UnaryOperationTypes.hpp"
#include "kasx/Domain.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
/**
 * @class UnaryOpearation
 * @brief Unary operation type struct
 *
 */
struct UnaryOpearation : public Expression {
  Expression expression;
  UNARY_OPERATION_TYPES operationType;

  UnaryOpearation(UNARY_OPERATION_TYPES operationType, const std::string& name, Expression expression,
                  Debug::DomainFileTrace trace)
      : Expression(false, EXPRESSION_TYPES::UNARY_OPERATION, name, trace), expression(std::move(expression)) {}
};
}  // namespace KasX::Compiler::DataStructures::Expressions
