/*
* File name: Declaration.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 12:37:24
// Date modified: 2026-03-20 23:44:17
* ------
*/
#pragma once

#include <kasx/Types.hpp>
#include <string>

#include "DeclarationTypes.hpp"
#include "Traceable.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
/**
 * @class Declaration
 * @brief Main declaration struct, all the Declarations must extend from this struct. And, this is an abstract type struct.
 *
 */
struct Declaration : public Traceable {
  enum class MUTABILITY : bool { IMMUTABLE, MUTABLE };
  MUTABILITY mutability;              /// The declaration is mutable or not
  DECLARATION_TYPES declarationType;  ///< Type of the declaration, check #DECLARATION_TYPES for more details.
  declaration_id id;                  ///< id of the declaration
  std::string name;                   ///< Name of the declaration.

  /**
   * @brief Declaration contructor function.
   *
   * @param name Name of the declaration.
   * @param declarationType Type of the declaration, options are included in #DECLARATION_TYPES
   */
  Declaration(std::string name, DECLARATION_TYPES declarationType, Debug::DomainFileTrace fileTrace,
              MUTABILITY mutability = MUTABILITY::IMMUTABLE);

  ~Declaration();
};
}  // namespace KasX::Compiler::DataStructures::Declarations
