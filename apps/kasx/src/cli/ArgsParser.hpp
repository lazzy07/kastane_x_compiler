#pragma once
#include "CompiledArgument.hpp"

namespace KasX::App::CLI {
class ArgsParser {
 public:
  ArgsParser();
  ~ArgsParser();
  CompiledArgument ParseArguments(int argc, char *argv[]);
};
}  // namespace KasX::App::CLI