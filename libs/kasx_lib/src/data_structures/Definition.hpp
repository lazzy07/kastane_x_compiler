#pragma once

#include <kasx/Types.hpp>
#include <string>

namespace KasX::Compiler::DataStructures {
struct Definition {
  definition_id id;
  std::string name;
  FileTrace trace;
};
}  // namespace KasX::Compiler::DataStructures