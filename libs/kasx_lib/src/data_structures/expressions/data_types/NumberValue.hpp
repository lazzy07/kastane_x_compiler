#pragma once

#include "../Expression.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct NumberValue : public Expression {
  number_value value;

  explicit NumberValue(number_value value) : Expression(EXPRESSION_TYPES::NUMBER_VALUE, PrimitiveOrNot::Primitive) {
    name = "Default: Number";
    value = value;
  };
};
}  // namespace KasX::Compiler::DataStructures
