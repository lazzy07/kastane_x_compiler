/*
* File name: KasXCompiler.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 13:28:40
// Date modified: 2025-12-14 13:28:57
* ------
*/

#pragma once

#include <Log.hpp>
#include <kasx/Types.hpp>
#include <lazlogger/LoggerManager.hpp>

namespace KasX::Compiler {
/**
 * @class KasXCompiler
 * @brief Entrypoint to the compiler.
 *
 * Controls all the functionality related to the compiler, internals and also entrypoint to other libraries and executables.
 *
 */
class KasXCompiler {
 public:
  KasXCompiler();
  ~KasXCompiler();

  /**
   * Compile a file read by the application.
   */
  void compile(DomainData data, COMPILER_OPTIONS options);

  /**
   * This function will initialize the logger functionality required to run the kasx_compiler
   */
  static void InitLogger();

 private:
  inline static std::unique_ptr<LazLogger::LoggerManager> s_Logger = nullptr;  // Reference to the LIB logger
};
}  // namespace KasX::Compiler
