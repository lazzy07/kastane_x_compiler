/*
* File name: Scope.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 19:46:10
// Date modified: 2026-08-30 10:51:18
* ------
*/

#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

namespace KasX::Compiler::Core::Scopes {
enum class SCOPE_TYPES : std::uint8_t { DEFAULT, GLOBAL, ACTION, TRIGGER, UTILITY, FOR_ALL };

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
   * @brief Scope constructor
   *
   * @param name Name of the scope
   * @param type Type of the scope see: @ref SCOPE_TYPES
   * @param domain Domain that owns this scope
   */
  Scope(std::string name, SCOPE_TYPES type);
  /**
   * @brief Scope destructor.
   */
  ~Scope();

 private:
  std::string m_Name;
  SCOPE_TYPES m_Type;
  bool m_ReplaceMode;  ///< Scope enters the replace mode
  std::unordered_map<std::string, std::string> m_ReplaceMap;
};
}  // namespace KasX::Compiler::Core::Scopes
