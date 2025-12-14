/**
 * @file TraceableClass.hpp
 * @brief Base class for classes that want to trace logging during domain compilation.
 *
 * For more infirmation, see the Scope.hpp
 */

#pragma once
#include <fmt/format.h>

#include <string>

#include "Log.hpp"

namespace KasX::Compiler::Core {

class TraceableClass {
 public:
  TraceableClass() = default;
  explicit TraceableClass(std::string traceName) : m_TraceName(std::move(traceName)) {}
  virtual ~TraceableClass() = default;

  void SetTraceName(std::string& name) { m_TraceName = std::move(name); };
  [[nodiscard]] const std::string& GetTraceName() const noexcept { return m_TraceName; };

  template <typename... Args>
  void TracePrint(fmt::format_string<Args...> fmt, Args&&... args) const {
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
