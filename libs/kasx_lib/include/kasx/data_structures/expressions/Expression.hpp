/*
* File name: Expression.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-20 23:38:51
// Date modified: 2026-03-20 23:42:22
* ------
*/

#include <string>

#include "ExpressionTypes.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
struct Expression {
  bool isPrimitive;
  EXPRESSION_TYPES expressionType;
  std::string name;
};
}  // namespace KasX::Compiler::DataStructures::Expressions
