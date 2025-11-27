#pragma once

#include "../Expression.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct NumberValue : public Expression {
  number_value value;

  NumberValue() : Expression(EXPRESSION_TYPES::NUMBER_VALUE) { name = "Default: Number"; };
};
}  // namespace KasX::Compiler::DataStructures
