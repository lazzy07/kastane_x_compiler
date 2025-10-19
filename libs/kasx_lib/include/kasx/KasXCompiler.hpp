#pragma once

#include <Log.hpp>
#include <kasx/Types.hpp>
#include <lazlogger/LoggerManager.hpp>

namespace KasX::Compiler {
class KasXCompiler {
 public:
  KasXCompiler();
  ~KasXCompiler();

  /**
   * Compile a file read by the application.
   */
  void Compile(DomainData data, COMPILER_OPTIONS options);

  /**
   * This function will initialize the logger functionality required to run the kasx_compiler
   */
  static void InitLogger();

 private:
  inline static std::unique_ptr<LazLogger::LoggerManager> s_Logger =
      nullptr;  // Reference to the LIB logger
};
}  // namespace KasX::Compiler