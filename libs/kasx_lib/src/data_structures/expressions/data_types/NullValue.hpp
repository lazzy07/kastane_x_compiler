#pragma once

#include "../Expression.hpp"
#include "../ExpressionTypes.hpp"

namespace KasX::Compiler::DataStructures {
struct NullValue : public Expression {
  explicit NullValue() : Expression(EXPRESSION_TYPES::NULL_VALUE, PrimitiveOrNot::Primitive) { name = "Default: NullValue"; };
};
}  // namespace KasX::Compiler::DataStructures
