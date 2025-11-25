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
    : Core::TraceableClass("Visitor"), KasXBaseVisitor(), m_Domain(domain) {
  CORE_TRACE("Program Visitor Initialized");
}

KasX::Compiler::Visitor::ProgramVisitor::~ProgramVisitor() { CORE_TRACE("Program Visitor Terminated"); }

void KasX::Compiler::Visitor::ProgramVisitor::PrintStartVisit(std::string_view type, std::string_view identifier) {
  if (identifier.empty()) {
    CLI_TRACE("\n[Visitor] ----- Started visit - type: {}", type);
    return;
  }
  CLI_TRACE("\n[Visitor] ----- Started visit - type: {}, id: '{}'", type, identifier);
}

void KasX::Compiler::Visitor::ProgramVisitor::PrintEndVisit(std::string_view type, std::string_view identifier) {
  if (identifier.empty()) {
    CLI_TRACE("[Visitor] ----- Ended visit - type: {}\n", type);
    return;
  }
  CLI_TRACE("[Visitor] ----- Ended visit - type: {}, id: '{}'\n", type, identifier);
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitTypeDeclarationNoParents(
    KasXParser::TypeDeclarationNoParentsContext* ctx) {
  std::string typeIdentifier = ctx->IDENTIFIER()->toString();
  PrintStartVisit("type-declaration (no parents)", typeIdentifier);

  antlr4::Token* token = ctx->IDENTIFIER()->getSymbol();
  linetrace_data line = token->getLine();
  linetrace_data column = token->getCharPositionInLine() + 1;
  linetrace_data end = column + typeIdentifier.length();

  KasX::Compiler::Trace::Range range;
  range.start.line = line;
  range.end.line = line;
  range.start.character = column;
  range.end.character = end;

  m_Domain->GetCurrentScope()->InitNewType(typeIdentifier, range);
  PrintEndVisit("type-declaration (no parents)", typeIdentifier);
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
  PrintStartVisit("type-declaration (with parents)", name);

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
  PrintEndVisit("type-declaration (with parents)", name);
  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitEntityDeclaration(KasXParser::EntityDeclarationContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  PrintStartVisit("entity-declaration", name);
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
  PrintEndVisit("entity-declaration", name);
  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitFluentDeclaration(KasXParser::FluentDeclarationContext* ctx) {
  PrintStartVisit("fluent-declaration", "");
  auto funcHeader = std::any_cast<std::pair<std::string, ParamList>>(visit(ctx->function_header()));

  std::string name = funcHeader.first;
  ParamList params = funcHeader.second;
  const std::string dataType = ctx->data_type()->getText();

  KasX::Compiler::Trace::Range range;

  m_Domain->GetCurrentScope()->InitNewFluent(name, range, params, dataType);
  PrintEndVisit("fluent-declaration", name);
  return {};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamWithoutDataType(KasXParser::ParamWithoutDataTypeContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();

  TracePrint("Visiting parameter '{}' without a datatype", name);

  return Param{name, ""};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamWithDataType(KasXParser::ParamWithDataTypeContext* ctx) {
  const std::string name = ctx->IDENTIFIER()->getText();
  const std::string dataType = ctx->data_type()->getText();

  TracePrint("Visiting parameter '{}' with datatype: '{}'", name, dataType);

  return Param{name, dataType};
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitParamList(KasXParser::ParamListContext* ctx) {
  const auto noOfElems = ctx->param().size();

  TracePrint("Visiting the parameter list with {} elements", noOfElems);

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
  TracePrint("Visiting Function header: '{}'", name);
  ParamList params;

  if (auto* paramList = ctx->param_list()) {              // guard: list is optional
    params = std::any_cast<ParamList>(visit(paramList));  // visit to get the value
  }

  return std::pair<std::string, ParamList>(name, std::move(params));
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprIdentifier(KasXParser::ExprIdentifierContext* ctx) {
  TracePrint("Visiting Identifier expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNumber(KasXParser::ExprNumberContext* ctx) {
  TracePrint("Visiting Number expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprUnknown(KasXParser::ExprUnknownContext* ctx) {
  TracePrint("Visiting Unknown expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNullClause(KasXParser::ExprNullClauseContext* ctx) {
  TracePrint("Visiting Null clause expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNot(KasXParser::ExprNotContext* ctx) {
  TracePrint("Visiting Not expression");

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprNegation(KasXParser::ExprNegationContext* ctx) {
  TracePrint("Visiting Negation expression");
  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitExprInheritance(KasXParser::ExprInheritanceContext* ctx) {
  TracePrint("Visiting Inheritance expression");
  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitInitialStateDecl(KasXParser::InitialStateDeclContext* ctx) {
  PrintStartVisit("initial-state", "");
  visit(ctx->arithmetic_expression());
  PrintEndVisit("initial-state", "");
  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitFluentVal(KasXParser::FluentValContext* ctx) {
  TracePrint("Visiting Fluent");
  auto fluent = ctx->IDENTIFIER()->getText();
  auto arguments = std::any_cast<std::vector<std::string>>(visit(ctx->argument_list()));

  Core::Scope* scope = m_Domain->GetCurrentScope();

  // Checking if the args mentioned in the fluent exists
  for (auto argument : arguments) {
    if (scope->GetDefinition(argument) == nullptr) {
      // username - lazzy07 TODO: Handle the error
      CLI_ERROR("Fluent argument: '{}' is missing", argument);
      return nullptr;
    }

    TracePrint("All the arguments of the fluent: '{}' found as definitions in the domain", fluent);
  }

  return 0;
}

std::any KasX::Compiler::Visitor::ProgramVisitor::visitArgumentList(KasXParser::ArgumentListContext* ctx) {
  TracePrint("Visting Argument List (Identifiers)");
  std::vector<std::string> arguments;

  for (auto* identifier : ctx->IDENTIFIER()) {
    arguments.push_back(identifier->getText());
  }

  return arguments;
}
