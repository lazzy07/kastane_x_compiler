#pragma once

#include <memory>
#include <vector>

#include "Definition.hpp"
#include "helpers/Parameter.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct FluentDecl : public Definition {
  definition_id dataType;
  std::vector<std::unique_ptr<Helpers::Parameter>> parameters;
};
}  // namespace KasX::Compiler::DataStructures
