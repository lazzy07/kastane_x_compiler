#pragma once

#include <vector>

#include "Expression.hpp"
#include "kasx/Types.hpp"
namespace KasX::Compiler::DataStructures {
struct Fluent : public Expression {
  std::vector<declaration_id> parameters;
};
}  // namespace KasX::Compiler::DataStructures
