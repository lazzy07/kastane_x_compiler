#pragma once

#include "../declarations/FluentDecl.hpp"
#include "GroundedExpression.hpp"
namespace KasX::Compiler::DataStructures::Grounded {
struct GroundedFluent : public GroundedExpression {
  FluentDecl* parentFluent;  ///< Parent fluent declaration that this fluent is based on
};
}  // namespace KasX::Compiler::DataStructures::Grounded
