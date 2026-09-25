/*
 * File name: ExistsOperation.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-25 16:59:03
 * Date modified: 2026-09-25 16:59:03
 * ------
 */

#include <vector>

#include "Log.hpp"
#include "kasx/core/scopes/Scope.hpp"
#include "kasx/data_structures/expressions/Expression.hpp"
#include "kasx/data_structures/expressions/ExpressionTypes.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
/**
 * @class ExistsOperation
 * @brief Exists operation data
 *
 */
struct ExistsOperation : public Expression {
  Core::Scopes::Scope* scope;
  std::vector<Expressions::ExpressionPtr> expressions;

  /**
   * @brief Contructor for Exists Opereation Expression
   *
   * @param trace Debug file trace
   */
  explicit ExistsOperation(Debug::DomainFileTrace trace)
      : Expression(false, EXPRESSION_TYPES::EXISTS_OPERATION, "Exists Operation", trace) {
    CLI_TRACE("Sum Expression Created");
  }
};
}  // namespace KasX::Compiler::DataStructures::Expressions
