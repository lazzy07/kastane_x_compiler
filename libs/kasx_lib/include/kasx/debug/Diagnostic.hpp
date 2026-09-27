/*
 * File name: Diagnostic.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-27 12:04:08
 * Date modified: 2026-09-27 12:04:08
 * ------
 */

#include <sys/types.h>

#include <cstdint>

#include "kasx/debug/DomainFileTrace.hpp"
namespace KasX::Compiler::Debug {
enum class SERVERITY : uint8_t { ERROR, WARNING, NOTE };

enum class DIAGNOSTIC_TYPE : uint8_t { PARSE_ERROR, COMPILER_ERROR };

/**
 * @class Diagnostic
 * @brief Diagnostic struct, which keeps track of all the errors and other diagnostics of the domain
 *
 */
struct Diagnostic {
  Debug::DomainFileTrace& trace;   ///< Trace of the diagnostic
  SERVERITY severity;              ///< Severity of the error/diagnsotic
  DIAGNOSTIC_TYPE diagnosticType;  ///< Type of the diagnostic
  std::string message;             ///< Message related to the error/diagnostic
};
}  // namespace KasX::Compiler::Debug
