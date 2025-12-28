/*
* File name: Domain.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 01:51:31
// Date modified: 2025-12-28 12:30:30
* ------
*/

#include <Log.hpp>
#include <kasx/Domain.hpp>
#include <memory>

#include "../visitors/AntlrSafeBase.hpp"
#include "../visitors/AntlrSafeRuntime.hpp"
#include "../visitors/ProgramVisitor.hpp"
#include "kasx/Types.hpp"

namespace KasX::Compiler::Core {
Domain::Domain(DomainData& data) : m_DomainData(std::move(data)) {
  m_ProgramVisitor = std::make_unique<Visitors::ProgramVisitor>(this);
  CORE_TRACE("Domain initialized");
};

Domain::~Domain() { CORE_TRACE("Domain Terminated"); };

void Domain::initVisitor() {
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

void Domain::initDefaultTypes() {}
}  // namespace KasX::Compiler::Core
