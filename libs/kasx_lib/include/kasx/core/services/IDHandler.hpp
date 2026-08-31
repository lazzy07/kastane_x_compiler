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
   *
   * @return Returns the next new ID for declarations
   */
  static KasX::declaration_id GetID();

  /**
   * @brief Returns an ID used for  expressions only
   *
   * @return Next avaialble expression id
   */
  static KasX::declaration_id GetExpressionID();

 private:
  static KasX::declaration_id currentLastID;            // Current last handed out id
  static KasX::declaration_id currentLastExpressionID;  // Last used expression id
};
}  // namespace KasX::Compiler::Core::Services
