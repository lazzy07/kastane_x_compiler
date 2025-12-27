/*
* File name: ProgramVisitor.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 15:12:03
// Date modified: 2025-12-27 11:39:09
* ------
*/

#include "ProgramVisitor.hpp"

#include "KasXParser.h"
#include "Log.hpp"
#include "kasx/Domain.hpp"
namespace KasX::Compiler::Visitors {
ProgramVisitor::ProgramVisitor(Core::Domain* domain) : m_Domain(domain) { CORE_TRACE("ProgramVisitor Initialized"); }

ProgramVisitor::~ProgramVisitor() { CORE_TRACE("ProgramVisitor Terminated"); }

std::any ProgramVisitor::visitTypeDeclaration(KasXParser::TypeDeclarationContext* ctx) {
  std::string typeDeclarationName = ctx->IDENTIFIER()->getText();

  ProgramVisitor::printStartVisit("Type-Declaration", typeDeclarationName);

  ProgramVisitor::printEndVisit("Type-Declaration", typeDeclarationName);

  return 0;
}

void ProgramVisitor::printStartVisit(std::string_view type, std::string_view identifier) {
  if (identifier.empty()) {
    CLI_TRACE("\n[Visitor] ----- Started visit - type: {}", type);
    return;
  }
  CLI_TRACE("\n[Visitor] ----- Started visit - type: {}, id: '{}'", type, identifier);
}

void ProgramVisitor::printEndVisit(std::string_view type, std::string_view identifier) {
  if (identifier.empty()) {
    CLI_TRACE("[Visitor] ----- Ended visit - type: {}\n", type);
    return;
  }
  CLI_TRACE("[Visitor] ----- Ended visit - type: {}, id: '{}'\n", type, identifier);
}
}  // namespace KasX::Compiler::Visitors
