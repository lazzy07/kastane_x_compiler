#pragma once

#include <string>
#include <vector>
#include <memory>
#include <utility>

namespace KasX::Compiler::DataStructures::Helpers {
  struct FunctionHeader{
    std::string name;
    std::vector<std::unique_ptr<std::pair<std::string, std::string>>> param;
  };
}