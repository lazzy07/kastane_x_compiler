/*
* File name: ProgramVisitor.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 15:12:03
// Date modified: 2025-12-30 22:07:11
* ------
*/

#include <kasx/debug/DomainFileTrace.hpp>
#include <kasx/visitors/ProgramVisitor.hpp>
#include <vector>

#include "KasXParser.h"
#include "Log.hpp"
#include "Token.h"
#include "kasx/Domain.hpp"

namespace KasX::Compiler::Visitors {
ProgramVisitor::ProgramVisitor(Core::Domain* domain) : m_Domain(domain) { CORE_TRACE("ProgramVisitor Initialized"); }

ProgramVisitor::~ProgramVisitor() { CORE_TRACE("ProgramVisitor Terminated"); }

std::any ProgramVisitor::visitTypeDeclaration(KasXParser::TypeDeclarationContext* ctx) {
  std::string typeDeclarationName = ctx->IDENTIFIER()->getText();

  ProgramVisitor::printStartVisit("Type-Declaration", typeDeclarationName);
  // Setting trace data
  antlr4::Token* startToken = ctx->getStart();
  antlr4::Token* endToken = ctx->getStop();

  Debug::DomainFileTrace::TraceData start{startToken->getLine(), startToken->getCharPositionInLine()};

  Debug::DomainFileTrace::TraceData end{endToken->getLine(),
                                        endToken->getCharPositionInLine() + static_cast<int>(endToken->getText().size() - 1)};

  // Debug Trace created to trace bugs with the domain file.
  Debug::DomainFileTrace trace{start, end};

  CLI_TRACE("File trace: {}", trace.toString());
  auto* tlContext = ctx->types_list();
  auto parents = (tlContext != nullptr) ? std::any_cast<std::vector<std::string>>(visit(tlContext)) : std::vector<std::string>{};

  if (parents.size() > 0) {
    CLI_TRACE("Type-Declaration '{}' has parents defined", typeDeclarationName);
  } else {
    parents.emplace_back("entity");  // Add 'entity' as a parent since there is no parent.
    CLI_TRACE("Type-Declaration '{}' does not have any parents defined, defaults to 'entity' type", typeDeclarationName);
  }

  // When function arrives here there is at least one parent associated to the type (entity or user-defined)

  ProgramVisitor::printEndVisit("Type-Declaration", typeDeclarationName);

  return 0;
}

std::any ProgramVisitor::visitTypesList(KasXParser::TypesListContext* ctx) {
  CLI_TRACE("Accessing types list");
  std::vector<std::string> out;
  std::vector<KasXParser::Type_nameContext*> items = ctx->type_name();
  out.reserve(items.size());

  for (auto* item : items) {
    out.emplace_back(item->getText());
  }
  CLI_TRACE("Types list access done");
  return out;
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
