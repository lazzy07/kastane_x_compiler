#pragma once

#include <memory>
#include <vector>

#include "Expression.hpp"
#include "ExpressionTypes.hpp"
#include "kasx/Types.hpp"
namespace KasX::Compiler::DataStructures {
struct Fluent : public Expression {
  Fluent() : Expression(EXPRESSION_TYPES::FLUENT) {
    isPrimitive = true;
  };  // Here the name of the fluent (Coming from the expression) will be set later.
  std::vector<declaration_id> parameters;
  std::unique_ptr<Expression> value;
};
}  // namespace KasX::Compiler::DataStructures
