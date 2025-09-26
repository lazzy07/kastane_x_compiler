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

KasX::Compiler::Visitor::ProgramVisitor::ProgramVisitor(KasX::Compiler::Core::Domain *domain)
    : KasXBaseVisitor(), m_Domain(domain) {
  CORE_TRACE("Program Visitor Initialized");
}

KasX::Compiler::Visitor::ProgramVisitor::~ProgramVisitor() {
  CORE_TRACE("Program Visitor Terminated");
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitTypeDeclarationNoParents(
    KasXParser::TypeDeclarationNoParentsContext *ctx) {
  antlr4::Token *token = ctx->IDENTIFIER()->getSymbol();
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

std::any KasX::Compiler::Visitor::ProgramVisitor::visitTypesList(
    KasXParser::TypesListContext *ctx) {
  std::vector<std::string> out;
  std::vector<KasXParser::Type_nameContext *> items =
      ctx->type_name();  // vector<Type_nameContext*>
  out.reserve(items.size());
  for (auto *item : items) out.emplace_back(item->getText());  // or visit(t).as<std::string>()
  return out;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitTypeDeclarationWithParents(
    KasXParser::TypeDeclarationWithParentsContext *ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  auto parents = std::any_cast<std::vector<std::string>>(visit(ctx->types_list()));
  CLI_TRACE("Visitor: Visiting type-declaration with parents: {}", name);

  antlr4::Token *token = ctx->IDENTIFIER()->getSymbol();
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

std::any KasX::Compiler::Visitor::ProgramVisitor::visitEntityDeclaration(
    KasXParser::EntityDeclarationContext *ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  CLI_TRACE("Visitor: Visiting entity-declaration: {}", name);
  auto parents = std::any_cast<std::vector<std::string>>(visit(ctx->types_list()));

  antlr4::Token *token = ctx->IDENTIFIER()->getSymbol();
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

std::any KasX::Compiler::Visitor::ProgramVisitor::visitFluentDeclaration(
    KasXParser::FluentDeclarationContext *ctx) {
  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamWithoutDataType(
    KasXParser::ParamWithoutDataTypeContext *ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();

  return std::pair<std::string, std::string>(name, "");
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamWithDataType(
    KasXParser::ParamWithDataTypeContext *ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();

  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamList(
    KasXParser::ParamListContext *ctx) {
  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitFunctionHeader(
    KasXParser::FunctionHeaderContext *ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  return {};
}