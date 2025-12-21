/*
* File name: Declaration.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 13:43:47
// Date modified: 2025-12-21 13:50:57
* ------
*/

#include <kasx/data_structures/declarations/Declaration.hpp>
#include <utility>

#include "Log.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
Declaration::Declaration(std::string name, DECLARATION_TYPES declarationType)
    : name(std::move(name)), declarationType(declarationType) {
  CORE_TRACE("A new declaration added: {}", name);
}
}  // namespace KasX::Compiler::DataStructures::Declarations
