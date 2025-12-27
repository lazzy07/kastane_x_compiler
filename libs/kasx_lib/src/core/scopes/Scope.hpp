/*
* File name: Scope.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 19:46:10
// Date modified: 2025-12-27 13:50:08
* ------
*/

#include <cstdint>

namespace KasX::Compiler::Core::Scopes {
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
  /**
   * @brief Scope constructor.
   */
  Scope();
  /**
   * @brief Scope destructor.
   */
  ~Scope();
};
}  // namespace KasX::Compiler::Core::Scopes
