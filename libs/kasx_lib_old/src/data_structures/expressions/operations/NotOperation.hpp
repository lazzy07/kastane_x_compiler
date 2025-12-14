#pragma once

#include "UnaryOperation.hpp"
#include "UnaryOperationTypes.hpp"
namespace KasX::Compiler::DataStructures {
struct NotOperation : public UnaryOperation {
  explicit NotOperation(Expression* expression) : UnaryOperation("Default: NotOperation") {
    operationType = UNARY_OPERATION_TYPES::UNARY_NOT;
  }
};
}  // namespace KasX::Compiler::DataStructures
