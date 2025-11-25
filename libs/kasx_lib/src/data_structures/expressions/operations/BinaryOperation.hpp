#pragma once
#include <memory>

#include "../Expression.hpp"
#include "BinaryOperationTypes.hpp"

namespace KasX::Compiler::DataStructures {
struct BooleanExpression : Expression {
  std::unique_ptr<Expression> left;
  std::unique_ptr<Expression> right;
  BINARY_OPERATION_TYPES binaryOp;
};
}  // namespace KasX::Compiler::DataStructures
