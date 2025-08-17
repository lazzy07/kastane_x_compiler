#include "ProgramVisitor.hpp"

#include "AntlrSafeBase.hpp"
// Fixer added
#include <Log.hpp>

KasX::Compiler::Visitor::ProgramVisitor::ProgramVisitor() {
  CORE_TRACE("Program Visitor Initialized");
}

KasX::Compiler::Visitor::ProgramVisitor::~ProgramVisitor() {
  CORE_TRACE("Program Visitor Terminated");
}
