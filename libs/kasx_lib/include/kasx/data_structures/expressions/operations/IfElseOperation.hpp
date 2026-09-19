/*
 * File name: IfElseOperation.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-18 09:47:29
 * Date modified: 2026-09-18 09:47:29
 * ------
 */

#pragma once

#include <vector>

#include "kasx/data_structures/expressions/Expression.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
/**
 * @class IfElseOperation
 * @brief If Else clause related data
 *
 */
struct IfElseOperation {
  std::vector<Expressions::ExpressionPtr> ifConditions;  ///< All the if and elseif boolean conditions
  std::vector<Expressions::ExpressionPtr>
      ifExpressions;  ///< Expressions that need to evaluate if the corresponding if or elseif condition is satisfied

  Expressions::ExpressionPtr elseExpression;  ///< Else part of the if condition
};
}  // namespace KasX::Compiler::DataStructures::Expressions
