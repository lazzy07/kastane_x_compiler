#pragma once

#include <vector>

#include "Declaration.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct TypeDecl : public Declaration {
  std::vector<declaration_id> parents;
  std::vector<declaration_id> children;
  std::vector<declaration_id> entities;
};
}  // namespace KasX::Compiler::DataStructures
