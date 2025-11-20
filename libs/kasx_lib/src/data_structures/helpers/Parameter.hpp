#pragma once

#include "../declarations/DeclarationTypes.hpp"
#include "kasx/Types.hpp"

// For processing param list
namespace KasX::Compiler::DataStructures::Helpers {
struct Parameter {
  definition_id id;
  std::string name;
  KasX::Compiler::DataStructures::DECLARATION_TYPES dataType;
  definition_id index;
};
}  // namespace KasX::Compiler::DataStructures::Helpers
