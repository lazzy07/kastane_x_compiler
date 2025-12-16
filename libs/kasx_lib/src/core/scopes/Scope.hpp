/*
* File name: Scope.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 19:46:10
// Date modified: 2025-12-14 19:53:17
* ------
*/

#include <cstdint>

namespace KasX::Compiler::Core::Scope {
enum class SCOPE_TYPES : std::uint8_t { DEFAULT, GLOBAL, ACTION, TRIGGER, UTILITY };

/**
 * @class Scope
 * @brief Virtual scope class, that all the scopes must extend from.
 *
 * Scope class holds data related to a specific scope, such as entities, types, etc.
 *
 */
class Scope {
 public:
  Scope();
  ~Scope();
};
}  // namespace KasX::Compiler::Core::Scope
