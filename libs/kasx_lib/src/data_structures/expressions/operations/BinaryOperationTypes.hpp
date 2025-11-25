#pragma once

#include <cstdint>

namespace KasX::Compiler::DataStructures {
enum BINARY_OPERATION_TYPES : std::uint8_t {
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
}  // namespace KasX::Compiler::DataStructures
