#pragma once

#include "../Expression.hpp"

namespace KasX::Compiler::DataStructures {
struct UnknownValue : public Expression {
  explicit UnknownValue() : Expression(EXPRESSION_TYPES::UNKNOWN_VALUE, PrimitiveOrNot::Primitive) { name = "Default: Unknown"; };
};
}  // namespace KasX::Compiler::DataStructures
