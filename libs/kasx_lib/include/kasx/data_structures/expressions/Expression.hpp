/*
* File name: Expression.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-20 23:38:51
// Date modified: 2026-08-19 01:17:19
* ------
*/

#include <string>
#include <utility>

#include "ExpressionTypes.hpp"
#include "kasx/data_structures/declarations/TypeDeclaration.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
/**
 * @class Expression
 * @brief Expression is the core of all the fluents and other value types, all the data types and operations must extend this
 * class
 *
 */
struct Expression {
  bool isPrimitive;  ///< If this is a primitive type of data this will be true: for example the integer value of 4. Otherwise:
                     ///< like binary operation, this will be false.
  EXPRESSION_TYPES expressionType;      ///< Type of the expression
  std::string name;                     ///< Name of the expression
  Declarations::TypeDeclaration* type;  ///< Type of the expression

  /**
   * @brief Constructor of the expression struct, the type of the expression will be assigned later.
   *
   * @param isPrimitive if the current expression is a primitive or not
   * @param expressionType Type of the expression
   * @param name Name of the expression
   */
  Expression(bool isPrimitive, EXPRESSION_TYPES expressionType, std::string name)
      : isPrimitive(isPrimitive), expressionType(expressionType), name(std::move(name)) {}
};
}  // namespace KasX::Compiler::DataStructures::Expressions
