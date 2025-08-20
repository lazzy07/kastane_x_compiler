#pragma once

#include <cinttypes>
#include <memory>
#include <string>
#include <vector>

#include "Definition.hpp"

namespace KasX::Compiler::DataStructures {
struct Type : public Definition {
  std::vector<definition_id> parents;
  std::vector<definition_id> children;
};
}  // namespace KasX::Compiler::DataStructures