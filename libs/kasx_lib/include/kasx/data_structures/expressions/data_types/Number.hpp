/*
* File name: Number.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-08-15 09:34:57
// Date modified: 2026-08-18 00:15:27
* ------
*/

#pragma once
#include "../Expression.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures::Expressions::DataTypes {
/**
 * @class Number
 * @brief Number value structure, self explainatory.
 *
 */
struct Number : public Expression {
  kasx_number value;  ///< Stored value

  explicit Number(kasx_number value) : value(value) {
    isPrimitive = true;
    expressionType = EXPRESSION_TYPES::NUMBER_VALUE;
  }
};
};  // namespace KasX::Compiler::DataStructures::Expressions::DataTypes
