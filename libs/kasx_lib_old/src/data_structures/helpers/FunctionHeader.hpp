#pragma once

#include <string>
#include <vector>

#include "Parameter.hpp"

namespace KasX::Compiler::DataStructures::Helpers {
struct FunctionHeader {
  std::string name;
  std::vector<Parameter> params;
};
}  // namespace KasX::Compiler::DataStructures::Helpers