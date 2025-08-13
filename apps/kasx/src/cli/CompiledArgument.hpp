#pragma once

#include <string>
#include <vector>

#include "../core/Execution.hpp"

namespace KasX::App::CLI {
struct CompiledArgument {
  int execution_type;
  std::string filePath;
};
}  // namespace KasX::App::CLI