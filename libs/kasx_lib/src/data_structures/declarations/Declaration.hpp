#pragma once

#include <kasx/Types.hpp>
#include <string>

#include "../../trace/Range.hpp"

namespace KasX::Compiler::DataStructures {
struct Declaration {
  declaration_id id;
  std::string name;
  KasX::Compiler::Trace::Range trace;
};
}  // namespace KasX::Compiler::DataStructures
