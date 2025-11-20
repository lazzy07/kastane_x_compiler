#pragma once

#include <vector>

#include "Declaration.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct TypeDecl : public Declaration {
  std::vector<definition_id> parents;
  std::vector<definition_id> children;
  std::vector<definition_id> entities;
};
}  // namespace KasX::Compiler::DataStructures
