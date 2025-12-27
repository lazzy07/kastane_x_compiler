/*
* File name: DomainFileTrace.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-27 14:55:27
// Date modified: 2025-12-27 15:06:06
* ------
*/

#include "kasx/Types.hpp"
namespace KasX::Compiler::Debug {
/**
 * @class DomainFileTrace
 * @brief Keeps information about errors, warnings, and etc. to give linter/debug information if there are any errors in the
 * problem file.
 *
 */
struct DomainFileTrace {
 private:
  /**
   * @class TraceData
   * @brief Used to keep track of where the information reside in the problem file (The .sabre) file
   *
   */
  struct TraceData {
    linetrace_data line;       ///< Line of the debug trace.
    linetrace_data character;  ///< Character of the debug trace.
  };

 public:
  TraceData start;  ///< Start of the debug trace.
  TraceData end;    ///< End of the debug trace.
};
}  // namespace KasX::Compiler::Debug
