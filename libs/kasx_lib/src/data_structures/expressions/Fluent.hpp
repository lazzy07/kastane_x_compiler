#pragma once

#include <memory>
#include <vector>

#include "Expression.hpp"
#include "kasx/Types.hpp"
namespace KasX::Compiler::DataStructures {
struct Fluent : public Expression {
  std::vector<declaration_id> parameters;
  std::unique_ptr<Expression> value;
};
}  // namespace KasX::Compiler::DataStructures
