#include "ProgramVisitor.hpp"

#include "../core/Domain.hpp"
// Fixer added
#include <Log.hpp>
#include <kasx/Types.hpp>

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
  size_t line = token->getLine();
  size_t column = token->getCharPositionInLine() + 1;

  std::string typeIdentifier = ctx->IDENTIFIER()->toString();
  CLI_TRACE("Visiting type-declraration without parents: {}", typeIdentifier);
  m_Domain->InitNewType(typeIdentifier, {line, column});
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

  antlr4::Token *token = ctx->IDENTIFIER()->getSymbol();
  size_t line = token->getLine();
  size_t column = token->getCharPositionInLine() + 1;

  m_Domain->InitNewType(name, {line, column}, parents);
  return {};
}
