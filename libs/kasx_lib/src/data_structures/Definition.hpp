#pragma once

#include <cstdint>
#include <kasx/Types.hpp>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace KasX::Compiler::DataStructures {
struct Definition {
  definition_id id;
  std::string name;
  FileTrace trace;
};
}  // namespace KasX::Compiler::DataStructures