/*
* File name: Declaration.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 12:37:24
// Date modified: 2025-12-30 18:59:57
* ------
*/
#pragma once

#include <kasx/Types.hpp>
#include <kasx/debug/DomainFileTrace.hpp>
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
  const Debug::DomainFileTrace fileTrace;   ///< Debug information about where this declaration is at in the domain file.

  /**
   * @brief Declaration contructor function.
   *
   * @param name Name of the declaration.
   * @param declarationType Type of the declaration, options are included in #DECLARATION_TYPES
   */
  Declaration(std::string name, DECLARATION_TYPES declarationType, Debug::DomainFileTrace fileTrace);
};
}  // namespace KasX::Compiler::DataStructures::Declarations
