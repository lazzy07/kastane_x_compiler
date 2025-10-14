#pragma once

#include "../DefinitionTypes.hpp"
#include "kasx/Types.hpp"

// For processing param list
namespace KasX::Compiler::DataStructures::Helpers {
struct Parameter {
  definition_id id;
  std::string name;
  KasX::Compiler::DataStructures::DEFINITION_TYPES dataType;
  definition_id index;
};
}  // namespace KasX::Compiler::DataStructures::Helpers