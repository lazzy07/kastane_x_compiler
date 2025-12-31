/*
* File name: Declaration.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 13:43:47
// Date modified: 2025-12-30 22:24:57
* ------
*/

#include <kasx/data_structures/declarations/Declaration.hpp>
#include <utility>

#include "Log.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
Declaration::Declaration(std::string name, DECLARATION_TYPES declarationType, Debug::DomainFileTrace fileTrace)
    : name(std::move(name)), declarationType(declarationType), fileTrace(fileTrace) {
  CORE_TRACE("A new declaration added: {}", name);
}
}  // namespace KasX::Compiler::DataStructures::Declarations
