#pragma once

#include <string>

#include "ExpressionTypes.hpp"

namespace KasX::Compiler::DataStructures {
/**
 * For better readability, instead of using true false values to check primitive or non-primitive expression types, use
 * PrimitiveOrNot type
 */
enum class PrimitiveOrNot : bool { Primitive = true, NonPrimitive = false };

/**
 * Main expression struct, all the expression must extend this struct
 */
struct Expression {
  std::string name;  // Name of the expression
  EXPRESSION_TYPES expressionType;
  bool isPrimitive;  // This will indicate if the expression value is a primitive type or not, for example True, False, and number
                     // value 1 are primitive.
  Expression(EXPRESSION_TYPES expressionType, PrimitiveOrNot isPrimitive)
      : expressionType(expressionType), isPrimitive(isPrimitive == PrimitiveOrNot::Primitive) {};
};
}  // namespace KasX::Compiler::DataStructures
