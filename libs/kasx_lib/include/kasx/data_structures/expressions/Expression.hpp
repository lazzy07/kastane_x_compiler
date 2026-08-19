/*
* File name: Expression.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-20 23:38:51
// Date modified: 2026-08-18 23:58:41
* ------
*/

#include <string>

#include "ExpressionTypes.hpp"
#include "kasx/data_structures/declarations/TypeDeclaration.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
struct Expression {
  bool isPrimitive;
  EXPRESSION_TYPES expressionType;
  std::string name;
  Declarations::TypeDeclaration* type;
};
}  // namespace KasX::Compiler::DataStructures::Expressions
