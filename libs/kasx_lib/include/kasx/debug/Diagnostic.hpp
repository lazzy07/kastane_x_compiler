/*
 * File name: Diagnostic.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-27 12:04:08
 * Date modified: 2026-09-27 12:04:08
 * ------
 */

#pragma once

#include <sys/types.h>

#include <cstdint>

#include "kasx/debug/DomainFileTrace.hpp"
namespace KasX::Compiler::Debug {
enum class SERVERITY : uint8_t { ERROR, WARNING, NOTE };

enum class DIAGNOSTIC_TYPE : uint8_t {
  PARSE_ERROR,                          ///< A parse related error
  UNKNOWN_COMPILER_ERROR,               ///< Unknown compiler error: an error other than the errors that are known
  ENTITY_NOT_DECLARED,                  ///< A reference to unknown entity found
  TYPE_NOT_DECLARED,                    ///< Data type not found in the global scope error
  UNRESOLVED_INITIAL_STATE_EXPRESSION,  ///< An unresolvable expression related to initial state
  EXPRESSION_TYPE_MISMATCH,             ///< Expression types mismatch issues like RHS is boolean and LHS is number
  NULL_EXPRESSION_TYPE,                 ///< Issues with expression types
};

/**
 * @class Diagnostic
 * @brief Diagnostic struct, which keeps track of all the errors and other diagnostics of the domain
 *
 */
struct Diagnostic {
  const Debug::DomainFileTrace trace;  ///< Trace of the diagnostic
  SERVERITY severity;                  ///< Severity of the error/diagnsotic
  DIAGNOSTIC_TYPE diagnosticType;      ///< Type of the diagnostic
  const std::string message;           ///< Message related to the error/diagnostic
  const std::string culprit;           ///< Actual text of the error
};
}  // namespace KasX::Compiler::Debug
