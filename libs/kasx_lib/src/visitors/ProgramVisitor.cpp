/*
* File name: ProgramVisitor.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 15:12:03
// Date modified: 2026-01-05 01:02:45
* ------
*/

#include <fmt/base.h>

#include <kasx/debug/DomainFileTrace.hpp>
#include <kasx/visitors/ProgramVisitor.hpp>
#include <vector>

#include "KasXParser.h"
#include "Log.hpp"
#include "Token.h"
#include "kasx/Domain.hpp"

namespace KasX::Compiler::Visitors {
using std::string;

ProgramVisitor::ProgramVisitor(Core::Domain* domain) : m_Domain(domain) { CORE_TRACE("ProgramVisitor Initialized"); }

ProgramVisitor::~ProgramVisitor() { CORE_TRACE("ProgramVisitor Terminated"); }

std::any ProgramVisitor::visitTypeDeclaration(KasXParser::TypeDeclarationContext* ctx) {
  std::string typeDeclarationName = ctx->IDENTIFIER()->getText();

  ProgramVisitor::PrintStartVisit("Type-Declaration", typeDeclarationName);
  // Setting trace data
  auto trace = getTraceData(ctx->getStart(), ctx->getStop());

  CLI_TRACE("File trace: {}", trace.toString());
  auto* tlContext = ctx->types_list();
  auto parents =
      (tlContext != nullptr) ? std::any_cast<std::vector<std::string>>(visit(tlContext)) : std::vector<std::string>{"entity"};

  // When function arrives here, there is at least one parent associated to the type (entity type or other user-defined type)
  this->m_Domain->getGlobalScope()->createTypeDeclaration(typeDeclarationName, parents, trace);

  ProgramVisitor::PrintEndVisit("Type-Declaration", typeDeclarationName);

  return 0;
}

Debug::DomainFileTrace ProgramVisitor::getTraceData(antlr4::Token* startToken, antlr4::Token* endToken) {
  Debug::DomainFileTrace::TraceData start{startToken->getLine(), startToken->getCharPositionInLine()};

  Debug::DomainFileTrace::TraceData end{endToken->getLine(),
                                        endToken->getCharPositionInLine() + static_cast<int>(endToken->getText().size() - 1)};

  // Debug Trace created to trace bugs with the domain file.
  Debug::DomainFileTrace trace{start, end};

  return trace;
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

void ProgramVisitor::PrintStartVisit(std::string_view type, std::string_view identifier) {
  if (identifier.empty()) {
    CLI_TRACE("\n[Visitor] ----- Started visit - type: {}", type);
    return;
  }
  CLI_TRACE("\n[Visitor] ----- Started visit - type: {}, id: '{}'", type, identifier);
}

void ProgramVisitor::PrintEndVisit(std::string_view type, std::string_view identifier) {
  if (identifier.empty()) {
    CLI_TRACE("[Visitor] ----- Ended visit - type: {}\n", type);
    return;
  }
  CLI_TRACE("[Visitor] ----- Ended visit - type: {}, id: '{}'\n", type, identifier);
}

void ProgramVisitor::EditParentsData(const string& typeDeclarationName, std::vector<std::string>& parents) {
  if (parents.size() > 0) {
    CLI_TRACE("Type-Declaration '{}' has parents defined", typeDeclarationName);
  } else {
    parents.emplace_back("entity");  // Add 'entity' as a parent since there is no parent.
    CLI_TRACE("Type-Declaration '{}' does not have any parents defined, defaults to 'entity' type", typeDeclarationName);
  }
}

std::any ProgramVisitor::visitEntityDeclaration(KasXParser::EntityDeclarationContext* ctx) {
  const std::string& entityName = ctx->IDENTIFIER()->toString();

  PrintStartVisit("Entity-Declaration", entityName);

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());

  auto* tlContext = ctx->types_list();
  auto types =
      (tlContext != nullptr) ? std::any_cast<std::vector<std::string>>(visit(tlContext)) : std::vector<std::string>{"entity"};

  m_Domain->getGlobalScope()->createEntityDeclaration(entityName, types, trace);

  CLI_TRACE("File trace: {}", trace.toString());
  PrintEndVisit("Entity-Declaration", entityName);

  return 0;
}

}  // namespace KasX::Compiler::Visitors
