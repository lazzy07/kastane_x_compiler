/*
* File name: BinaryOperation.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-08-18 23:37:04
// Date modified: 2026-08-19 01:09:52
* ------
*/

#pragma once

#include "BinaryOperationTypes.hpp"
#include "kasx/Domain.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
struct BinaryOperation : public Expression {
  Expression left;
  Expression right;

  BINARY_OPERATION_TYPES operationType;
};
}  // namespace KasX::Compiler::DataStructures::Expressions
