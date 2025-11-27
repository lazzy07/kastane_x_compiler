#pragma once

#include "../Expression.hpp"

namespace KasX::Compiler::DataStructures {
struct UnknownValue : Expression {
  UnknownValue() : Expression(EXPRESSION_TYPES::UNKNOWN_VALUE) { name = "Default: Unknown"; };
};
}  // namespace KasX::Compiler::DataStructures
