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
#include <memory>
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
  Scope(std::string name, SCOPE_TYPES type, Scope* parent = nullptr);
  /**
   * @brief Scope destructor.
   */
  ~Scope();

  /**
   * @brief Returns the parent pointer of this scope
   *
   * @return Parent scope as a pointer (const)
   */
  Scope* getParentScope() const { return m_Parent; };

  /**
   * @brief Get the current replace map from the scope.
   *
   * @return Replace map
   */
  const std::unordered_map<std::string, std::string>& getReplaceMap() const { return m_ReplaceMap; };

  /**
   * @brief Return the replace string for the perticular string that being replaced with
   *
   * @param name Name that trying to replace
   * @return Name that is being replaced, returns the same name if it does not exists.
   */
  std::string getReplaceString(const std::string& name);

  /**
   * @brief Enable replace mode for this scope
   */
  void enableReplaceMode();

  /**
   * @brief Disables the replace mode
   */
  void disableReplaceMode();

  bool isReplaceModeOn() const { return m_ReplaceMode; };

  /**
   * @brief Add a replace pair to the scope
   *
   * @param identifier Identifier to replace
   * @param replace replacing phrase
   */
  void addIdentifierToReplace(const std::string& identifier, const std::string& replace);

  /**
   * @brief Creates a child scope with the current scope as the parent
   *
   * @param name Name of the child scope
   * @param type Scope type
   * @return Returns a pointer to the newly created child scope
   */
  Scope* createChildScope(const std::string& name, SCOPE_TYPES type);

 private:
  Scope* m_Parent;
  std::string m_Name;
  SCOPE_TYPES m_Type;
  bool m_ReplaceMode;  ///< Scope enters the replace mode
  std::unordered_map<std::string, std::string> m_ReplaceMap;
  std::unordered_map<std::string, std::unique_ptr<Scope>> m_ChildScopes;
};
}  // namespace KasX::Compiler::Core::Scopes
