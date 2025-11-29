#pragma once
#include <memory>

#include "../Expression.hpp"
#include "BinaryOperationTypes.hpp"

namespace KasX::Compiler::DataStructures {
struct BooleanExpression : Expression {
  explicit BooleanExpression(std::string name) : Expression(EXPRESSION_TYPES::BINARY_OPERATION) { name = name; }

  std::unique_ptr<Expression> left;
  std::unique_ptr<Expression> right;
  BINARY_OPERATION_TYPES operationType;
};
}  // namespace KasX::Compiler::DataStructures
