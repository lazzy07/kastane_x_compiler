/*
* File name: BinaryOperationTypes.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-04-10 14:43:10
// Date modified: 2026-08-18 23:40:25
* ------
*/

#pragma once

#include <cstdint>
namespace KasX::Compiler::DataStructures::Expressions {
enum class BINARY_OPERATION_TYPES : std::uint8_t {
  SUBSTRACTION,
  ADDITION,
  DIVISION,
  MULTIPLICATION,
  LESS_THAN,
  GREATER_THAN,
  LESS_THAN_OR_EQUAL,
  GREATER_THAN_OR_EQUAL,
  NOT_EQUAL,
  EQUAL_TO,
  ASSIGNMENT,
  DISJUNCTION,
  CONJUNCTION,
  INHERITANCE
};
}  // namespace KasX::Compiler::DataStructures::Expressions
