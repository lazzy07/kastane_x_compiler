/*
* File name: Scope.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 19:46:10
// Date modified: 2025-12-28 12:25:54
* ------
*/

#include <cstdint>
#include <string>

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
  Scope(std::string name, SCOPE_TYPES type);
  /**
   * @brief Scope destructor.
   */
  ~Scope();

 private:
  std::string m_Name;
  SCOPE_TYPES m_Type;
};
}  // namespace KasX::Compiler::Core::Scopes
