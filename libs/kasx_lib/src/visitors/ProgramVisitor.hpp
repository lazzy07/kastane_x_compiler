/*
* File name: ProgramVisitor.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 14:20:04
// Date modified: 2025-12-21 15:15:31
* ------
*/
#pragma once
#include "../core/logging/TraceableClass.hpp"
#include "AntlrSafeBase.hpp"
#include "kasx/Domain.hpp"

namespace KasX::Compiler::Visitors {
class ProgramVisitor : public KasXBaseVisitor, public Core::TraceableClass {
 public:
  explicit ProgramVisitor(Core::Domain* domain);

  ~ProgramVisitor() override;

 private:
  Core::Domain* m_Domain;
};
}  // namespace KasX::Compiler::Visitors
