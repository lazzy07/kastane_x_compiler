#pragma once

#include <string>

#include "ExpressionTypes.hpp"

namespace KasX::Compiler::DataStructures {
/**
 * Main expression struct, all the expression must extend this struct
 */
struct Expression {
  explicit Expression(EXPRESSION_TYPES type) { this->expression_type = type; };
  std::string name;  // Name of the expression
  EXPRESSION_TYPES expression_type;
};
}  // namespace KasX::Compiler::DataStructures
