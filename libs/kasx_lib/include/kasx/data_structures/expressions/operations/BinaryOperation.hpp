/*
* File name: BinaryOperation.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-08-18 23:37:04
// Date modified: 2026-08-18 23:41:55
* ------
*/

#pragma once

#include <memory>

#include "BinaryOperationTypes.hpp"
#include "kasx/Domain.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
struct BinaryOperation : public Expression {
  std::unique_ptr<Expression> left;
  std::unique_ptr<Expression> right;

  BINARY_OPERATION_TYPES operationType;
};
}  // namespace KasX::Compiler::DataStructures::Expressions
