/*
* File name: GroundedFluent.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-20 15:45:45
// Date modified: 2026-03-20 16:00:04
* ------
*/

#pragma once

#include <vector>

#include "kasx/data_structures/declarations/EntityDeclaration.hpp"
#include "kasx/data_structures/declarations/FluentDeclaration.hpp"
#include "kasx/data_structures/declarations/TypeDeclaration.hpp"
namespace KasX::Compiler::DataStructures::Grounded {
/**
 * @class GroundedFluent
 * @brief Grounded version of the Fluent Declaration.
 *
 */
struct GroundedFluent {
  std::string name;                                       ///< Name of the grounded fluent, path(Castle, Mountain)
  std::vector<Declarations::EntityDeclaration> entities;  ///< Entities in the fluent
  Declarations::TypeDeclaration* type;                    ///< Type of the fluent
  Declarations::FluentDeclaration* parent;                ///< Parent declaration of the grounded fluent
};
}  // namespace KasX::Compiler::DataStructures::Grounded
