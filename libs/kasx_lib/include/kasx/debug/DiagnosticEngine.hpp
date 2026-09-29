/*
 * File name: DiagnosticEngine.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-27 12:52:05
 * Date modified: 2026-09-27 12:52:05
 * ------
 */

#pragma once

#include <string>
#include <vector>

#include "Diagnostic.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace antlr4 {
class CharStream;
}

namespace KasX::Compiler::Debug {
class DiagnosticEngine {
 public:
  /**
   * @brief Diagnostic engine constructor
   */
  explicit DiagnosticEngine();

  void init(antlr4::CharStream* charStream);

  /**
   * @brief Diagnostic engine distructor
   */
  ~DiagnosticEngine();

  /**
   * @brief Creates a diagnostic report for an error
   *
   * @param trace Trace of the diagnostic or error
   * @param severity Severity of the error
   * @param diagnosticType Type of the diagnostic
   * @param message Message of the error
   */
  void createDiagnostic(const Debug::DomainFileTrace* trace, SERVERITY severity, DIAGNOSTIC_TYPE diagnosticType,
                        const std::string& message);

  /**
   * @brief Get the culprit string from the domain file
   *
   * @param trace Domain file trace
   * @return returns the actual string that correspond to the error
   */
  std::string getCulpritStr(const Debug::DomainFileTrace* trace);

  /**
   * @brief Creates the final diagnostic report and returns the report as a string
   *
   * @return final diagnostic report as a string
   */
  const std::string& createDiagnosticReport();

 private:
  std::vector<Diagnostic> m_Diagnostics;
  std::string m_DiagnosticReport;

  antlr4::CharStream* m_Input;
  size_t m_ErrorCount = 0;  ///< Error count means the diagnoses that actually are considered errors: excluding Warnings etc.
};
}  // namespace KasX::Compiler::Debug
