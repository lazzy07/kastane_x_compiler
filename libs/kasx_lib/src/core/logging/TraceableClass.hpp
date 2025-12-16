/*
* File name: TraceableClass.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 13:31:10
// Date modified: 2025-12-15 22:19:27
* ------
*/

#pragma once

#include <fmt/format.h>

#include <string>

#include "Log.hpp"

namespace KasX::Compiler::Core {

/**
 * @class TraceableClass
 * @brief Base class for classes that want to trace logging during domain compilation.
 *
 * For more information, see Scope.hpp
 *
 */
class TraceableClass {
 public:
  TraceableClass() = default;

  /**
   * @brief Constructor that takes traceName as an argument.
   *
   * @param traceName The name being used for printing (Logging).
   */
  explicit TraceableClass(std::string traceName) : m_TraceName(std::move(traceName)) {}
  virtual ~TraceableClass() = default;

  /**
   * @brief This function can be used to set the trace (log trace) name of the class.
   *
   * @param name Name of the class.
   */
  void setTraceName(std::string& name) { m_TraceName = std::move(name); };
  /**
   * @brief Get the trace name that has being set.
   *
   * @return Get the name of the class, that being used for logging.
   */
  [[nodiscard]] const std::string& getTraceName() const noexcept { return m_TraceName; };

  /**
   * @brief Template function used for printing/tracing.
   *
   * @tparam Args Argument type passed into the function.
   * @param fmt Formatter string eg: "Hello {}".
   * @param args Arguments to the string, "World".
   */
  template <typename... Args>
  void tracePrint(fmt::format_string<Args...> fmt, Args&&... args) const {
    if (!m_TraceName.empty()) {
      // Prefix with trace name if set
      CLI_TRACE("[{}] {}", m_TraceName, fmt::format(fmt, std::forward<Args>(args)...));
    } else {
      // Fallback: behave exactly like CLI_TRACE
      CLI_TRACE(fmt, std::forward<Args>(args)...);
    }
  }

 private:
  std::string m_TraceName;
};
}  // namespace KasX::Compiler::Core
