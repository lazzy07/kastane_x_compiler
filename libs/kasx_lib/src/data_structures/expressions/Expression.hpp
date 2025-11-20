#pragma once

#include "kasx/Types.hpp"
namespace KasX::Compiler::DataStructures {
/**
 * Main expression struct, all the expression must extend this struct
 */
struct Expression {
  definition_id id;      // Id of the expression
  definition_id parent;  // Declaration/Definition id of the expression (Declaration ID)
  std::string name;      // Name of the expression
};
}  // namespace KasX::Compiler::DataStructures
