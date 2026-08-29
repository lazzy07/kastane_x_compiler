/*
* File name: Expression.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-20 23:38:51
// Date modified: 2026-08-20 13:03:48
* ------
*/

#pragma once

#include <memory>
#include <string>
#include <utility>

#include "ExpressionTypes.hpp"
#include "Log.hpp"
#include "kasx/Types.hpp"
#include "kasx/data_structures/declarations/Traceable.hpp"
#include "kasx/data_structures/declarations/TypeDeclaration.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
/**
 * @class Expression
 * @brief Expression is the core of all the fluents and other value types, all the expression types and operations must extend
 * this class
 *
 */
struct Expression : public Declarations::Traceable {
  declaration_id id;  ///< ID of the expression
  bool isPrimitive;   ///< If this is a primitive type of data this will be true: for example the integer value of 4. Otherwise:
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
   * @param fileTrace Debug file trace
   */
  Expression(bool isPrimitive, EXPRESSION_TYPES expressionType, std::string name, Debug::DomainFileTrace fileTrace)
      : Traceable(fileTrace), isPrimitive(isPrimitive), expressionType(expressionType), name(std::move(name)) {
    CLI_TRACE("Exression created with Name: {}", name);
  }

  virtual ~Expression() = default;
};

/**
 * @brief Polymorphic handle to an Expression (or any of its derived types eg: Fluent, BinaryOperation).
 * Visitor functions that build up expression trees pass their results around using this alias so that
 * derived-type data (like a Fluent's arguments) survives being handed back through std::any.
 */
using ExpressionPtr = std::shared_ptr<Expression>;
}  // namespace KasX::Compiler::DataStructures::Expressions
