/*
* File name: ForAll.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-08-29 12:36:53
// Date modified: 2026-08-29 12:59:49
* ------
*/

#pragma once
#include <vector>

#include "../Expression.hpp"
#include "../ExpressionTypes.hpp"
#include "Log.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
/**
 * @class ForAll
 * @brief For all is a for loop expression in Sabre language, holds a vector of all the expressions (with grounded fluents) in the
 * for loop
 *
 */
struct ForAllOperation : public Expression {
  std::vector<ExpressionPtr> expressions;

  explicit ForAllOperation(Debug::DomainFileTrace fileTrace)
      : Expression(false, EXPRESSION_TYPES::FORALL_OPERATION, "For-All Operation", fileTrace) {
    CLI_TRACE("For-All Expression Created");
  };
};
}  // namespace KasX::Compiler::DataStructures::Expressions
