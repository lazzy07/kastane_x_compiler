/*
* File name: ExpressionTypes.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-20 23:33:11
// Date modified: 2026-03-20 23:38:26
* ------
*/

#include <cstdint>

namespace KasX::Compiler::DataStructures::Expressions {
enum class EXPRESSION_TYPES : std::uint8_t {
  FLUENT,
  NUMBER_VALUE,
  UNKNOWN_VALUE,
  NULL_VALUE,
  UNARY_OPERATION,
  BINARY_OPERATION,
  IDENTIFIER
};
}  // namespace KasX::Compiler::DataStructures::Expressions
