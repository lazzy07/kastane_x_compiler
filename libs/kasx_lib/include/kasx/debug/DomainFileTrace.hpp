/*
* File name: DomainFileTrace.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-27 14:55:27
// Date modified: 2026-01-01 10:01:18
* ------
*/
#pragma once

#include <cstddef>
#include <limits>
#include <sstream>
#include <string>

#include "kasx/Types.hpp"

// Forward declared on purpose: including ANTLR headers here undefines the EOF macro (antlr4-common.h) for every file that
// includes this header, which breaks fmt/spdlog. Include ANTLR in .cpp files through AntlrSafeRuntime.hpp instead.
namespace antlr4 {
class Token;
}

namespace KasX::Compiler::Debug {

/**
 * @class DomainFileTrace
 * @brief Keeps information about errors, warnings, and etc. to give linter/debug information if there are any errors in the
 * problem file.
 *
 */
struct DomainFileTrace {
 public:
  /**
   * @class TraceData
   * @brief Used to keep track of where the information reside in the problem file (The .sabre) file
   *
   */
  struct TraceData {
    linetrace_data line;       ///< Line of the debug trace. 1 - based numbering
    linetrace_data character;  ///< Character of the debug trace. 0 - based numbering

    [[nodiscard]] std::string toString() const {
      std::ostringstream oss;
      oss << line << ":" << character;
      return oss.str();
    }
  };

  TraceData start;  ///< Start of the debug trace.
  TraceData end;    ///< End of the debug trace.

  /// Same value as ANTLR's INVALID_INDEX macro, which is not visible here (see the forward declaration above).
  static constexpr size_t INVALID_SOURCE_INDEX = std::numeric_limits<size_t>::max();

  size_t startIndex = INVALID_SOURCE_INDEX;  ///< Index of the first character in the input stream
  size_t stopIndex = INVALID_SOURCE_INDEX;   ///< Index of the last character (inclusive)

  [[nodiscard]] bool hasSourceRange() const {
    return startIndex != INVALID_SOURCE_INDEX && stopIndex != INVALID_SOURCE_INDEX && stopIndex >= startIndex;
  }

  /**
   * @brief Trace data related to the domain file, where information exists etc.
   *
   * @param start Start of the trace.
   * @param end End of the trace.
   */
  DomainFileTrace(TraceData start, TraceData end) : start(start), end(end) {}

  static DomainFileTrace GetDefaultFileTrace() { return DomainFileTrace({0, 0}, {0, 0}); }

  /**
   * @brief toString function returns information about the problem file position of the declaration
   *
   * @return Position of the file from-to
   */
  [[nodiscard]] std::string toString() const {
    std::ostringstream oss;
    oss << start.toString() << " - " << end.toString();
    return oss.str();
  }

  static DomainFileTrace GetTraceData(antlr4::Token* start, antlr4::Token* stop);
};

}  // namespace KasX::Compiler::Debug
