/*
* File name: UnaryOperation.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-08-18 23:40:48
// Date modified: 2026-08-19 01:09:28
* ------
*/

#pragma once

#include "UnaryOperationTypes.hpp"
#include "kasx/Domain.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
/**
 * @class UnaryOpearation
 * @brief Unary operation type struct
 *
 */
struct UnaryOpearation : public Expression {
  Expression left;
  UNARY_OPERATION_TYPES operationType;
};
}  // namespace KasX::Compiler::DataStructures::Expressions
