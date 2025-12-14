#pragma once

#include "GroundedExpressionTypes.hpp"
#include "kasx/Types.hpp"
namespace KasX::Compiler::DataStructures::Grounded {
/**
 * @class GroundedExpression
 * @brief This is the base class of the all grounded actions / fluents and other data.
 *
 * Make sure to extend all the ground data structures from this class.
 */
struct GroundedExpression {
  declaration_id id;                         ///< Grounded expression id
  GROUNDED_EXPRESSION_TYPES expressionType;  ///< Type of the grounded expression
};
}  // namespace KasX::Compiler::DataStructures::Grounded
