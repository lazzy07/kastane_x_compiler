/*
* File name: Declaration.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 12:37:24
// Date modified: 2025-12-15 22:25:17
* ------
*/
#pragma once

#include <kasx/Types.hpp>
#include <string>

#include "DeclarationTypes.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
/**
 * @class Declaration
 * @brief Main declaration struct, all the Declarations must extend from this struct. And, this is an abstract type struct.
 *
 */
struct Declaration {
  const std::string name;                   ///< Name of the declaration.
  const DECLARATION_TYPES declarationType;  ///< Type of the declaration, check #DECLARATION_TYPES for more details.

  /**
   * @brief Declaration contructor function.
   *
   * @param name Name of the declaration.
   * @param declarationType Type of the declaration, options are included in #DECLARATION_TYPES
   */
  Declaration(std::string name, DECLARATION_TYPES declarationType);
};
}  // namespace KasX::Compiler::DataStructures::Declarations
