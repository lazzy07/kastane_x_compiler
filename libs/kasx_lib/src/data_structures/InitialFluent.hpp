#pragma once
#include "Definition.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::DataStructures {
/**
 * @brief Initial fluent stores initial value of a fluent, defined in the problem file.
 *
 */
struct InitialFluent : Definition {
  definition_id fluentID;
  void *value;
};
}  // namespace KasX::Compiler::DataStructures