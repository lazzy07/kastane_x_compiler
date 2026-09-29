/*
 * File name: DiagnosticEngine.cpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-27 16:36:31
 * Date modified: 2026-09-27 16:36:31
 * ------
 */

#include "kasx/debug/DiagnosticEngine.hpp"

#include "../visitors/AntlrSafeRuntime.hpp"
#include "Log.hpp"

namespace KasX::Compiler::Debug {

DiagnosticEngine::DiagnosticEngine() { CORE_TRACE("Diagnostic engine initialized"); }

void DiagnosticEngine::init(antlr4::CharStream* charStream) {
  CORE_TRACE("Diagnostic engine: Character stream is set");
  m_Input = charStream;
}

DiagnosticEngine::~DiagnosticEngine() { CORE_TRACE("Diagnostic engine terminated"); }

void DiagnosticEngine::createDiagnostic(const Debug::DomainFileTrace* trace, SERVERITY severity, DIAGNOSTIC_TYPE diagnosticType,
                                        const std::string& message) {
  m_Diagnostics.emplace_back(Diagnostic{trace, severity, diagnosticType, message});
  CORE_TRACE("New diagnostic log added: {}", message);
}

std::string DiagnosticEngine::getCulpritStr(const Debug::DomainFileTrace* trace) {
  if (!trace->hasSourceRange() || trace->stopIndex >= m_Input->size()) {
    return {};
  }
  return m_Input->getText(antlr4::misc::Interval(trace->startIndex, trace->stopIndex));
}

const std::string& DiagnosticEngine::createDiagnosticReport() { return m_DiagnosticReport; }
}  // namespace KasX::Compiler::Debug
