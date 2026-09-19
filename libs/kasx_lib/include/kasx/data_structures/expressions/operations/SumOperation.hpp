/*
 * File name: SumOperation.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-19 12:39:00
 * Date modified: 2026-09-19 12:39:00
 * ------
 */

#include <vector>

#include "kasx/core/scopes/Scope.hpp"
#include "kasx/data_structures/expressions/Expression.hpp"
namespace KasX::Compiler::DataStructures::Expressions {
/**
 * @class SumOperation
 * @brief Summation operation data
 *
 */
struct SumOperation : public Expression {
  Core::Scopes::Scope* scope;
  std::vector<Expressions::ExpressionPtr> expressions;
};
}  // namespace KasX::Compiler::DataStructures::Expressions
