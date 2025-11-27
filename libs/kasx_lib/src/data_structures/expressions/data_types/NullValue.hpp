#pragma once

#include "../Expression.hpp"
#include "../ExpressionTypes.hpp"

namespace KasX::Compiler::DataStructures {
struct NullValue : public Expression {
  NullValue() : Expression(EXPRESSION_TYPES::NULL_VALUE) { name = "Default: Null"; }
};
}  // namespace KasX::Compiler::DataStructures
