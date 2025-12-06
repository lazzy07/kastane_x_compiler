#pragma once
#include "CompiledArgument.hpp"

namespace KasX::App::CLI {
class ArgsParser {
 public:
  ArgsParser();
  ~ArgsParser();
  CompiledArgument parseArguments(int argc, char* argv[]);
};
}  // namespace KasX::App::CLI
