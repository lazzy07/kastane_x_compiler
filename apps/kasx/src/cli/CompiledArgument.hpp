#pragma once

#include <string>

namespace KasX::App::CLI {
struct CompiledArgument {
  int execution_type;
  std::string filePath;
};
}  // namespace KasX::App::CLI