#include "Domain.hpp"

#include <Log.hpp>

#include "KasXLexer.h"
#include "Scope.hpp"

KasX::Compiler::Core::Domain::Domain(DomainData &data)
    : m_GlobalScope("global", SCOPE_TYPES::GLOBAL) {
  CORE_TRACE("Domain Initialized");

  m_DomainData = std::move(data);
  m_ProgramVisitor = std::make_unique<Visitor::ProgramVisitor>(this);

  // Making the global scope the current scope at the begining
  m_CurrentScope = &m_GlobalScope;
}

KasX::Compiler::Core::Domain::~Domain() { CORE_TRACE("Domain Terminated"); }

void KasX::Compiler::Core::Domain::InitVisitor() {
  CORE_TRACE("Visitor Started");

  antlr4::ANTLRInputStream input(m_DomainData.fileStream);
  KasXLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  KasXParser parser(&tokens);

  antlr4::tree::ParseTree *tree = parser.prog();

  CLI_INFO("Parse tree completed: {}", m_DomainData.domainName);

  CLI_INFO("Visiting parse tree of {}", m_DomainData.domainName);
  this->InitDefaultTypes();
  m_ProgramVisitor->visit(tree);
}

void KasX::Compiler::Core::Domain::InitDefaultTypes() {
  CLI_TRACE("Initial types added: number, boolean, entity, character");

  // Initializing default types of Sabre domains.
  this->m_GlobalScope.InitNewType("entity", {});
  this->m_GlobalScope.InitNewType("character", {});
  this->m_GlobalScope.InitNewType("number", {});
  this->m_GlobalScope.InitNewType("boolean", {});
}