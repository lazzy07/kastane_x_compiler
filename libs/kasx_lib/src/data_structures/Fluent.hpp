#pragma once

#include <vector>

#include "Definition.hpp"
#include "helpers/Parameter.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct Fluent : public Definition {
  definition_id dataType;
  std::vector<Helpers::Parameter> parameters;
};
}  // namespace KasX::Compiler::DataStructures