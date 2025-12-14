#include "Domain.hpp"

#include <Log.hpp>

#include "ActionScope.hpp"
#include "KasXLexer.h"

KasX::Compiler::Core::Domain::Domain(DomainData& data) {
  CORE_TRACE("Domain Initialized");

  m_DomainData = std::move(data);
  m_ProgramVisitor = std::make_unique<Visitor::ProgramVisitor>(this);

  // Making the global scope the current scope at the begining
  m_CurrentScope = &m_GlobalScope;
}

KasX::Compiler::Core::Domain::~Domain() { CORE_TRACE("Domain Terminated"); }

void KasX::Compiler::Core::Domain::initVisitor() {
  CORE_TRACE("Visitor Started");

  antlr4::ANTLRInputStream input(m_DomainData.fileStream);
  KasXLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  KasXParser parser(&tokens);

  antlr4::tree::ParseTree* tree = parser.prog();

  CLI_INFO("Parse tree completed: {}", m_DomainData.domainName);

  CLI_INFO("Visiting parse tree of {}", m_DomainData.domainName);
  this->initDefaultTypes();
  m_ProgramVisitor->visit(tree);
}

void KasX::Compiler::Core::Domain::initDefaultTypes() {
  CLI_TRACE("Initial types added: number, boolean, entity, character");

  // Initializing default types of Sabre domains.
  this->m_GlobalScope.initNewType("entity", {}, {}, true);
  this->m_GlobalScope.initNewType("character", {}, {}, true);
  this->m_GlobalScope.initNewType("number", {});
  this->m_GlobalScope.initNewType("boolean", {});
}

KasX::Compiler::Core::ActionScope* KasX::Compiler::Core::Domain::createActionScope(std::string name) {
  ActionScope* currentScope = this->getGlobalScope()->createActionScope(name);
  CLI_TRACE("Current scope changed to : {}", name);
  m_CurrentScope = currentScope;

  return currentScope;
}

void KasX::Compiler::Core::Domain::resetScope() {
  m_CurrentScope = this->getGlobalScope();
  CLI_TRACE("Current scope changed back to the global scope");
}
