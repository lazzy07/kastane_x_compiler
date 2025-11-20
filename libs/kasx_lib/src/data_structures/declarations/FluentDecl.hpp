#pragma once

#include <memory>
#include <vector>

#include "../helpers/Parameter.hpp"
#include "Declaration.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
struct FluentDecl : public Declaration {
  definition_id dataType;
  std::vector<std::unique_ptr<Helpers::Parameter>> parameters;
};
}  // namespace KasX::Compiler::DataStructures
