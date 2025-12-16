/*
* File name: EntityDeclaration.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 16:46:52
// Date modified: 2025-12-15 16:50:16
* ------
*/
#pragma once

#include "Declaration.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
/**
 * @class EntityDeclaration
 * @brief Entities in the domain and relatedb data to that entity.
 */
struct EntityDeclaration : public Declaration {};
}  // namespace KasX::Compiler::DataStructures::Declarations
