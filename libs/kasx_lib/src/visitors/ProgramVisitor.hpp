#pragma once


#include <any>
#include "AntlrSafeBase.hpp"

namespace KasX::Compiler::Core {
class Domain;
}

namespace KasX::Compiler::Visitor {
class ProgramVisitor : public KasXBaseVisitor {
 public:
  explicit ProgramVisitor(KasX::Compiler::Core::Domain *domain);
  ~ProgramVisitor() override;

  std::any visitTypeDeclarationNoParents(KasXParser::TypeDeclarationNoParentsContext *ctx) override;
  std::any visitTypesList(KasXParser::TypesListContext *ctx) override;
  std::any visitTypeDeclarationWithParents(
      KasXParser::TypeDeclarationWithParentsContext *ctx) override;
  std::any visitEntityDeclaration(KasXParser::EntityDeclarationContext *ctx) override;
  std::any visitFluentDeclaration(KasXParser::FluentDeclarationContext *ctx) override;
  std::any visitFunctionHeader(KasXParser::FunctionHeaderContext* ctx) override;
  std::any visitParamList(KasXParser::ParamListContext* ctx) override;
  std::any visitParamWithDataType(KasXParser::ParamWithDataTypeContext* ctx) override;
  std::any visitParamWithoutDataType(KasXParser::ParamWithoutDataTypeContext* ctx) override;
 private:
  KasX::Compiler::Core::Domain *m_Domain;
};
}  // namespace KasX::Compiler::Visitor