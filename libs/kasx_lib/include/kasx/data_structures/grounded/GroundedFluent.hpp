/*
* File name: GroundedFluent.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-20 15:45:45
// Date modified: 2026-03-20 18:59:56
* ------
*/

#pragma once

#include <vector>

#include "kasx/Types.hpp"
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
  declaration_id id;                                       ///< ID for the fluent
  std::string name;                                        ///< Name of the grounded fluent, path(Castle,Mountain)
  std::vector<Declarations::EntityDeclaration*> entities;  ///< Entities in the fluent
  Declarations::TypeDeclaration* type;                     ///< Type of the fluent
  Declarations::FluentDeclaration* parent;                 ///< Parent declaration of the grounded fluent

  /**
   * @brief Grounded fluent constructor
   *
   * @param fluent Fluent declaration that this grounded fluent based on
   * @param entities Entities that fluent is build upon
   */
  explicit GroundedFluent(Declarations::FluentDeclaration* fluent, const std::vector<Declarations::EntityDeclaration*>& entities);

 private:
  [[nodiscard]] std::string generateName(const std::string& partialName);
};
}  // namespace KasX::Compiler::DataStructures::Grounded
