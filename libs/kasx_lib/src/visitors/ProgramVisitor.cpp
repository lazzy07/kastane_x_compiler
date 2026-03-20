/*
* File name: ProgramVisitor.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 15:12:03
// Date modified: 2026-03-20 15:41:32
* ------
*/

#include <fmt/base.h>

#include <any>
#include <kasx/data_structures/declarations/FluentDeclaration.hpp>
#include <kasx/data_structures/declarations/helpers/Parameter.hpp>
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

std::any ProgramVisitor::visitFluentDeclaration(KasXParser::FluentDeclarationContext* ctx) {
  PrintStartVisit("Fluent-Declaration", "");
  auto functionHeader = std::any_cast<DataStructures::Declarations::Helpers::FunctionHeader>(visit(ctx->function_header()));
  const std::string& fluentName = functionHeader.name;
  CLI_TRACE("Fluent name identified : {}", fluentName);

  const std::string& dataTypeStr = ctx->data_type()->getText();

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());

  m_Domain->getGlobalScope()->createFluentDeclaration(fluentName, functionHeader, dataTypeStr, trace);

  PrintEndVisit("Fluent-Declaration", fluentName);
  return 0;
}

std::any ProgramVisitor::visitFunctionHeader(KasXParser::FunctionHeaderContext* ctx) {
  const std::string& functionName = ctx->IDENTIFIER()->toString();

  CLI_TRACE("Accessing function header: {}", functionName);
  auto trace = getTraceData(ctx->getStart(), ctx->getStop());
  auto functionHeader = DataStructures::Declarations::Helpers::FunctionHeader(functionName, trace);
  functionHeader.parameters =
      std::any_cast<std::vector<DataStructures::Declarations::Helpers::Parameter>>(visit(ctx->param_list()));
  CLI_TRACE("Accessing function header done");

  return functionHeader;
}

std::any ProgramVisitor::visitParamList(KasXParser::ParamListContext* ctx) {
  CLI_TRACE("Accessing param list");
  std::vector<DataStructures::Declarations::Helpers::Parameter> out;
  std::vector<KasXParser::ParamContext*> items = ctx->param();
  out.reserve(items.size());

  for (KasXParser::ParamContext* item : items) {
    auto param = std::any_cast<DataStructures::Declarations::Helpers::Parameter>(visit(item));
    out.push_back(param);
  }

  CLI_TRACE("Param list access done");

  return out;
}

std::any ProgramVisitor::visitParam(KasXParser::ParamContext* ctx) {
  const std::string& paramName = ctx->IDENTIFIER()->toString();
  CLI_TRACE("Visiting param: {}", paramName);

  auto trace = getTraceData(ctx->getStart(), ctx->getStop());
  auto param = DataStructures::Declarations::Helpers::Parameter(paramName, trace);

  auto* const paramType = ctx->data_type();

  if (paramType == nullptr) {
    param.isTypeDeclaration = false;
    CLI_TRACE("Param {} has been identified as an entity", paramName);
    auto* entityType = m_Domain->getGlobalScope()->getEntityDeclaration(paramName);

    if (entityType == nullptr) {
      // TODO: lazzy07 - Handle error
      CLI_ERROR("Entity type: {} not declared in the global scope", paramName);
    } else {
      param.entityType = entityType;
      CLI_TRACE("Entity type found in the global scope: {} and added to the param: {}", entityType->name, param.name);
    }
  } else {
    param.isTypeDeclaration = true;
    const std::string& dataTypeStr = paramType->getText();
    auto* dataType = m_Domain->getGlobalScope()->getTypeDeclaration(dataTypeStr);

    if (dataType == nullptr) {
      // TODO: lazzy07 - Handle error
      CLI_ERROR("Could not find the data type: {} in the global scope for param: {}", dataTypeStr, param.name);
    } else {
      param.dataType = dataType;
      CLI_TRACE("Param {} has been identified as data type: {}", param.name, param.dataType->name);
    }
  }

  CLI_TRACE("Visiting param: {} done", param.name);

  return param;
}
}  // namespace KasX::Compiler::Visitors
