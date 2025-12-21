/*
* File name: ProgramVisitor.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 15:12:03
// Date modified: 2025-12-21 15:16:25
* ------
*/

#include "ProgramVisitor.hpp"

#include "Log.hpp"
#include "kasx/Domain.hpp"
namespace KasX::Compiler::Visitors {
ProgramVisitor::ProgramVisitor(Core::Domain* domain) : m_Domain(domain) { CORE_TRACE("ProgramVisitor Initialized"); }

ProgramVisitor::~ProgramVisitor() { CORE_TRACE("ProgramVisitor Terminated"); }
}  // namespace KasX::Compiler::Visitors
