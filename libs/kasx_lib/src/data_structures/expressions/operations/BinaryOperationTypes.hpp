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

constexpr const char* binaryOperationToString(BINARY_OPERATION_TYPES operation) {
  switch (operation) {
    case SUBSTRACTION:
      return "SUBSTRACTION";
    case ADDITION:
      return "ADDITION";
    case DIVISION:
      return "DIVISION";
    case MULTIPLICATION:
      return "MULTIPLICATION";
    case LESS_THAN:
      return "LESS_THAN";
    case GREATER_THAN:
      return "GREATER_THAN";
    case LESS_THAN_OR_EQUAL:
      return "LESS_THAN_OR_EQUAL";
    case GREATER_THAN_OR_EQUAL:
      return "GREATER_THAN_OR_EQUAL";
    case NOT_EQUAL:
      return "NOT_EQUAL";
    case EQUAL_TO:
      return "EQUAL_TO";
    case ASSIGNMENT:
      return "ASSIGNMENT";
    case DISJUNCTION:
      return "DISJUNCTION";
    case CONJUNCTION:
      return "CONJUNCTION";
    case INHERITANCE:
      return "INHERITANCE";
  }
  return "<UNKNOWN_BINARY_OP>";
}

}  // namespace KasX::Compiler::DataStructures
