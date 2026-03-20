/*
* File name: Declaration.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 13:43:47
// Date modified: 2026-03-20 12:40:51
* ------
*/

#include <kasx/data_structures/declarations/Declaration.hpp>
#include <utility>

#include "Log.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
Declaration::Declaration(std::string name, DECLARATION_TYPES declarationType, Debug::DomainFileTrace fileTrace,
                         MUTABILITY mutability)
    : Traceable(fileTrace), name(std::move(name)), declarationType(declarationType), mutability(mutability) {}

Declaration::~Declaration() { CLI_TRACE("Declaration: {} got deleted", this->name); }

}  // namespace KasX::Compiler::DataStructures::Declarations
