#pragma once

#include "../trace/Range.hpp"
#include <kasx/Types.hpp>
#include <string>

namespace KasX::Compiler::DataStructures {
struct Definition {
  definition_id id;
  std::string name;
  KasX::Compiler::Trace::Range trace;
};
}  // namespace KasX::Compiler::DataStructures