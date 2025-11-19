#pragma once

#include <vector>

#include "Definition.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct TypeDecl : public Definition {
  std::vector<definition_id> parents;
  std::vector<definition_id> children;
  std::vector<definition_id> entities;
};
}  // namespace KasX::Compiler::DataStructures
