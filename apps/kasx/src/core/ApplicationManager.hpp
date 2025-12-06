#pragma once

#include "../cli/CompiledArgument.hpp"
#include "Execution.hpp"

namespace KasX::App::Core {
class ApplicationManager {
 public:
  explicit ApplicationManager(KasX::App::CLI::CompiledArgument arguments);
  ~ApplicationManager();

  void execute();

 private:
  KasX::App::CLI::CompiledArgument m_Arguments;
};
}  // namespace KasX::App::Core
