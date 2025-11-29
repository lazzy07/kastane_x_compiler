#pragma once

#include <string>

#include "ExpressionTypes.hpp"

namespace KasX::Compiler::DataStructures {
/**
 * Main expression struct, all the expression must extend this struct
 */
struct Expression {
  explicit Expression(EXPRESSION_TYPES type) { this->expressionType = type; };
  std::string name;  // Name of the expression
  EXPRESSION_TYPES expressionType;
  bool isPrimitive;  // This will indicate if the expression value is a primitive type or not, for example True, False, and number
                     // value 1 are primitive.
};
}  // namespace KasX::Compiler::DataStructures
