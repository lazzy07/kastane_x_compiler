/*
* File name: ExpressionTypes.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-20 23:33:11
// Date modified: 2026-08-19 13:57:21
* ------
*/

#pragma once

#include <cstdint>

namespace KasX::Compiler::DataStructures::Expressions {
enum class EXPRESSION_TYPES : std::uint8_t {
  FLUENT,
  NUMBER_OPERATION,
  UNKNOWN_VALUE,
  NULL_VALUE,
  UNARY_OPERATION,
  BINARY_OPERATION,
  IDENTIFIER,
  BELIEVES_OPERATION
};
}  // namespace KasX::Compiler::DataStructures::Expressions
