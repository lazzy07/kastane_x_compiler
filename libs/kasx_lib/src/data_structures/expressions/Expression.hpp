#pragma once

#include "ExpressionTypes.hpp"
#include "kasx/Types.hpp"
namespace KasX::Compiler::DataStructures {
/**
 * Main expression struct, all the expression must extend this struct
 */
struct Expression {
  declaration_id id;      // Id of the expression
  declaration_id parent;  // Declaration/Definition id of the expression (Declaration ID)
  std::string name;       // Name of the expression
  EXPRESSION_TYPES expression_type;
};
}  // namespace KasX::Compiler::DataStructures
