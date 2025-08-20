#pragma once

#include <memory>

#include "AntlrSafeBase.hpp"

namespace KasX::Compiler::Core {
class Domain;
}

namespace KasX::Compiler::Visitor {
class ProgramVisitor : public KasXBaseVisitor {
 public:
  ProgramVisitor(KasX::Compiler::Core::Domain *domain);
  ~ProgramVisitor();

  std::any visitTypeDeclarationNoParents(KasXParser::TypeDeclarationNoParentsContext *ctx) override;
  std::any visitTypesList(KasXParser::TypesListContext *ctx) override;
  std::any visitTypeDeclarationWithParents(
      KasXParser::TypeDeclarationWithParentsContext *ctx) override;

 private:
  KasX::Compiler::Core::Domain *m_Domain;
};
}  // namespace KasX::Compiler::Visitor