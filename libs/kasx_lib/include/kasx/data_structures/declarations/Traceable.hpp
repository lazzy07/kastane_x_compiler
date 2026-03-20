/*
* File name: Traceable.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-20 12:33:43
// Date modified: 2026-03-20 12:52:28
* ------
*/

#include <kasx/debug/DomainFileTrace.hpp>

namespace KasX::Compiler::DataStructures::Declarations {
/**
 * @class Traceable
 * @brief Traceable type data structure, this structu supposed to be an abstract supporter class for all the traceable data
 * structures
 *
 */
struct Traceable {
  Debug::DomainFileTrace fileTrace;  ///< Debug information about where this declaration is at in the domain file.

  /**
   * @brief Traceable data constructor
   *
   * @param fileTrace File debug information
   */
  explicit Traceable(Debug::DomainFileTrace fileTrace) : fileTrace(fileTrace) {};
};
}  // namespace KasX::Compiler::DataStructures::Declarations
