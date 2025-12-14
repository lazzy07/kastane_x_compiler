#pragma once
#include <memory>

#include "../Expression.hpp"
#include "BinaryOperationTypes.hpp"

namespace KasX::Compiler::DataStructures {
struct BinaryOperation : public Expression {
  explicit BinaryOperation(BINARY_OPERATION_TYPES type)
      : Expression(EXPRESSION_TYPES::BINARY_OPERATION, PrimitiveOrNot::NonPrimitive) {
    name = binaryOperationToString(type);
    operationType = type;
  }

  std::unique_ptr<Expression> left;
  std::unique_ptr<Expression> right;
  BINARY_OPERATION_TYPES operationType;
};
}  // namespace KasX::Compiler::DataStructures
