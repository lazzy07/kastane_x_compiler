#include "ProgramVisitor.hpp"

#include "../core/Domain.hpp"
#include "KasXParser.h"
// Fixer added
#include <Log.hpp>
#include <any>
#include <kasx/Types.hpp>
#include <utility>
#include <vector>

#include "../trace/Range.hpp"

KasX::Compiler::Visitor::ProgramVisitor::ProgramVisitor(KasX::Compiler::Core::Domain* domain)
    : KasXBaseVisitor(), m_Domain(domain) {
  CORE_TRACE("Program Visitor Initialized");
}

KasX::Compiler::Visitor::ProgramVisitor::~ProgramVisitor() { CORE_TRACE("Program Visitor Terminated"); }

std::any KasX::Compiler::Visitor::ProgramVisitor::visitTypeDeclarationNoParents(
    KasXParser::TypeDeclarationNoParentsContext* ctx) {
  antlr4::Token* token = ctx->IDENTIFIER()->getSymbol();
  linetrace_data line = token->getLine();
  linetrace_data column = token->getCharPositionInLine() + 1;

  std::string typeIdentifier = ctx->IDENTIFIER()->toString();
  CLI_TRACE("Visitor: Visiting type-declaration without parents: {}", typeIdentifier);

  linetrace_data end = column + typeIdentifier.length();

  KasX::Compiler::Trace::Range range;
  range.start.line = line;
  range.end.line = line;
  range.start.character = column;
  range.end.character = end;

  m_Domain->GetCurrentScope()->InitNewType(typeIdentifier, range);
  return nullptr;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitTypesList(KasXParser::TypesListContext* ctx) {
  std::vector<std::string> out;
  std::vector<KasXParser::Type_nameContext*> items = ctx->type_name();  // vector<Type_nameContext*>
  out.reserve(items.size());
  for (auto* item : items) out.emplace_back(item->getText());  // or visit(t).as<std::string>()
  return out;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitTypeDeclarationWithParents(
    KasXParser::TypeDeclarationWithParentsContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  auto parents = std::any_cast<std::vector<std::string>>(visit(ctx->types_list()));
  CLI_TRACE("Visitor: Visiting type-declaration with parents: {}", name);

  antlr4::Token* token = ctx->IDENTIFIER()->getSymbol();
  size_t line = token->getLine();
  size_t column = token->getCharPositionInLine() + 1;

  linetrace_data end = column + name.length();

  KasX::Compiler::Trace::Range range;
  range.start.line = line;
  range.end.line = line;
  range.start.character = column;
  range.end.character = end;

  m_Domain->GetCurrentScope()->InitNewType(name, range, parents);
  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitEntityDeclaration(KasXParser::EntityDeclarationContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  CLI_TRACE("Visitor: Visiting entity-declaration: {}", name);
  auto parents = std::any_cast<std::vector<std::string>>(visit(ctx->types_list()));

  antlr4::Token* token = ctx->IDENTIFIER()->getSymbol();
  size_t line = token->getLine();
  size_t column = token->getCharPositionInLine() + 1;

  linetrace_data end = column + name.length();

  KasX::Compiler::Trace::Range range;
  range.start.line = line;
  range.end.line = line;
  range.start.character = column;
  range.end.character = end;

  m_Domain->GetCurrentScope()->InitNewEntity(name, range, parents);
  // m_Domain->InitNewEntity(name, {line, column}, parents);

  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitFluentDeclaration(KasXParser::FluentDeclarationContext* ctx) {
  auto funcHeader = std::any_cast<std::pair<std::string, ParamList>>(visit(ctx->function_header()));

  std::string name = funcHeader.first;
  ParamList params = funcHeader.second;

  const std::string dataType = ctx->data_type()->getText();

  KasX::Compiler::Trace::Range range;

  m_Domain->GetCurrentScope()->InitNewFluent(name, range, params, dataType);
  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamWithoutDataType(KasXParser::ParamWithoutDataTypeContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();

  CLI_TRACE("Visitor: Visiting parameter '{}' without a datatype", name);

  return Param{name, ""};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamWithDataType(KasXParser::ParamWithDataTypeContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  const std::string dataType = ctx->data_type()->getText();

  CLI_TRACE("Visitor: Visiting parameter '{}' with datatype: '{}'", name, dataType);

  return Param{name, dataType};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamList(KasXParser::ParamListContext* ctx) {
  const auto noOfElems = ctx->param().size();

  CLI_TRACE("Visitor: Visiting the parameter list with {} elements", noOfElems);

  ParamList out;
  out.reserve(noOfElems);

  for (auto* pctx : ctx->param()) {
    auto param = std::any_cast<Param>(visit(pctx));
    out.push_back(std::move(param));
  }

  return out;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitFunctionHeader(KasXParser::FunctionHeaderContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  CLI_TRACE("Visitor: Visiting Function header: {}", name);
  ParamList params;

  if (auto* paramList = ctx->param_list()) {              // guard: list is optional
    params = std::any_cast<ParamList>(visit(paramList));  // visit to get the value
  }

  return std::pair<std::string, ParamList>(name, std::move(params));
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprIdentifier(KasXParser::ExprIdentifierContext* ctx) {
  CLI_TRACE("Visitor: Visiting Identifier expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNumber(KasXParser::ExprNumberContext* ctx) {
  CLI_TRACE("Visitor: Visiting Number expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprUnknown(KasXParser::ExprUnknownContext* ctx) {
  CLI_TRACE("Visitor: Visiting Unknown expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNullClause(KasXParser::ExprNullClauseContext* ctx) {
  CLI_TRACE("Visitor: Visiting Null clause expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNot(KasXParser::ExprNotContext* ctx) {
  CLI_TRACE("Visitor: Visiting Not expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNegation(KasXParser::ExprNegationContext* ctx) {
  CLI_TRACE("Visitor: Visiting Negation expression");
  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprInheritance(KasXParser::ExprInheritanceContext* ctx) {
  CLI_TRACE("Visitor: Visiting Inheritance expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitInitialStateDecl(KasXParser::InitialStateDeclContext* ctx) {
  CLI_TRACE("Visitor: Visiting Initial State Declaration");
  visit(ctx->arithmetic_expression());
  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitFluentVal(KasXParser::FluentValContext* ctx) {
  CLI_TRACE("Visitor: Visiting Fluent");
  auto arguments = std::any_cast<std::vector<std::string>>(visit(ctx->argument_list()));
  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitArgumentList(KasXParser::ArgumentListContext* ctx) {
  CLI_TRACE("Visitor: Visting Argument List (Identifiers)");
  std::vector<std::string> arguments;

  for (auto* identifier : ctx->IDENTIFIER()) {
    arguments.push_back(identifier->getText());
  }

  return arguments;
}
