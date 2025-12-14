#pragma once

#include <memory>
#include <utility>

#include "../Expression.hpp"
#include "UnaryOperationTypes.hpp"

namespace KasX::Compiler::DataStructures {
struct UnaryOperation : public Expression {
  std::unique_ptr<Expression> expression;
  UNARY_OPERATION_TYPES operationType;

  explicit UnaryOperation(std::string name) : Expression(EXPRESSION_TYPES::UNARY_OPERATION, PrimitiveOrNot::NonPrimitive) {
    name = std::move(name);
  }
};
}  // namespace KasX::Compiler::DataStructures
