#pragma once

#include "../Expression.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct IdentifierPointer : public Expression {
  explicit IdentifierPointer(declaration_id identifier)
      : Expression(EXPRESSION_TYPES::IDENTIFIER_POINTER, PrimitiveOrNot::NonPrimitive) {};
};
}  // namespace KasX::Compiler::DataStructures
