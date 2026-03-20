/*
* File name: IDHandler.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-19 12:26:46
// Date modified: 2026-03-20 16:03:33
* ------
*/

#pragma once

#include <kasx/Types.hpp>

namespace KasX::Compiler::Core::Services {
/**
 * @class IDHandler
 * @brief IDHandler handles the destribution for declarations (proper declaration ids)
 *
 */
class IDHandler {
 public:
  /**
   * @brief Generates and returns a new ID for declarations, so that all the declarations have new and unique IDs.
   */
  static KasX::declaration_id GetID();

 private:
  static KasX::declaration_id currentLastID;  // Current last handed out id
};
}  // namespace KasX::Compiler::Core::Services
