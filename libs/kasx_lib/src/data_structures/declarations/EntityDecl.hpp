#pragma once

#include <vector>

#include "Declaration.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct EntityDecl : public Declaration {
  std::vector<definition_id> types;
};
}  // namespace KasX::Compiler::DataStructures
