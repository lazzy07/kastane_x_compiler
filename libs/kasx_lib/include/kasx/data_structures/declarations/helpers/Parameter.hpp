/*
* File name: Parameter.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 18:25:58
// Date modified: 2026-03-20 12:48:22
* ------
*/

#pragma once

#include "../EntityDeclaration.hpp"
#include "../TypeDeclaration.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Declarations::Helpers {
/**
 * @class Parameter
 * @brief Parameter helper class, used in ActionDeclarations, Fluents, Triggers.
 *
 */
struct Parameter : public Traceable {
  std::string name;  ///< Name of the parameter, coming from the domain file.
  TypeDeclaration*
      dataType;  ///< Type of the parameter, this will be null if the parameter type is just an entity instead of a type.
  EntityDeclaration* entityType;  ///< If the parameter is an entity, it will be pointed here.
  bool isTypeDeclaration;         ///< This will be true if the parameter type is an entity.

  Parameter(std::string name, Debug::DomainFileTrace trace);
};
}  // namespace KasX::Compiler::DataStructures::Declarations::Helpers
