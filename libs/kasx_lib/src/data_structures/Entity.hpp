#pragma once

#include <vector>

#include "Definition.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct Entity : public Definition {
  std::vector<definition_id> types;
};
}  // namespace KasX::Compiler::DataStructures