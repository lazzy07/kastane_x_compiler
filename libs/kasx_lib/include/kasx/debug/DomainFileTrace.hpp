/*
* File name: DomainFileTrace.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-27 14:55:27
// Date modified: 2025-12-30 22:09:34
* ------
*/
#pragma once

#include <sstream>
#include <string>

#include "kasx/Types.hpp"
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

  DomainFileTrace(TraceData start, TraceData end) : start(start), end(end) {}

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
};
}  // namespace KasX::Compiler::Debug
