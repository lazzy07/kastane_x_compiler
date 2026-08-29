/*
* File name: BinaryOperation.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-08-18 23:37:04
// Date modified: 2026-08-19 15:19:16
* ------
*/

#pragma once

#include <utility>

#include "../Expression.hpp"
#include "BinaryOperationTypes.hpp"
#include "Log.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
struct BinaryOperation : public Expression {
  ExpressionPtr left;
  ExpressionPtr right;

  BINARY_OPERATION_TYPES operationType;

  BinaryOperation(BINARY_OPERATION_TYPES operationType, const std::string& name, ExpressionPtr left, ExpressionPtr right,
                  Debug::DomainFileTrace trace)
      : Expression(false, EXPRESSION_TYPES::BINARY_OPERATION, name, trace),
        operationType(operationType),
        left(std::move(left)),
        right(std::move(right)) {
    CLI_TRACE("Binary operation created: {}", name);
  };
};
}  // namespace KasX::Compiler::DataStructures::Expressions
