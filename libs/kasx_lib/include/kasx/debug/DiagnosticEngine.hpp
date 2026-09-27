/*
 * File name: DiagnosticEngine.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-27 12:52:05
 * Date modified: 2026-09-27 12:52:05
 * ------
 */

#include <vector>

#include "Diagnostic.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::Debug {
class DiagnosticEngine {
 public:
  /**
   * @brief Diagnostic engine constructor
   */
  DiagnosticEngine();

  /**
   * @brief Diagnostic engine distructor
   */
  ~DiagnosticEngine();

  /**
   * @brief Creates a diagnostic report for an error
   *
   * @param trace Trace of the diagnostic or error
   * @param severity Severity of the error
   * @param message Message of the error
   */
  void createDiagnostic(Debug::DomainFileTrace& trace, SERVERITY severity, DIAGNOSTIC_TYPE diagnosticType,
                        const std::string& message);

  /**
   * @brief Creates the final diagnostic report and returns the report as a string
   *
   * @return final diagnostic report as a string
   */
  const std::string& createDiagnosticReport();

 private:
  std::vector<Diagnostic> m_Diagnostics;
  std::string m_DiagnosticReport;
};
}  // namespace KasX::Compiler::Debug
