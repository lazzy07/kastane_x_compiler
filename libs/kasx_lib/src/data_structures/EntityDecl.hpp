#pragma once

#include <vector>

#include "Definition.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct EntityDecl : public Definition {
  std::vector<definition_id> types;
};
}  // namespace KasX::Compiler::DataStructures
