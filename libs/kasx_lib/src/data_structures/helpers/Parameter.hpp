#pragma once

#include "../Type.hpp"
#include "kasx/Types.hpp"

// For processing param list
namespace KasX::Compiler::DataStructures::Helpers {
struct Parameter {
  definition_id id;
  std::string name;
  std::unique_ptr<KasX::Compiler::DataStructures::Type> dataType;
};
}  // namespace KasX::Compiler::DataStructures::Helpers