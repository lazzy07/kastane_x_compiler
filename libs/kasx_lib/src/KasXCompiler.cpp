#include <Log.hpp>
#include <kasx/KasXCompiler.hpp>
#include <lazlogger/LoggerManager.hpp>

KasX::Compiler::KasXCompiler::KasXCompiler() {
  auto logger = LazLogger::LoggerManager();

  logger.Initialize({.core = {.name = CORE_LOGGER_NAME, .file = "log/core/kasx_compiler_lib.txt"},
                     .cli = {.name = CLI_LOGGER_NAME, .file = "log/cli/kasx_log_lib.txt"}});

  CORE_TRACE("Compiler Initialized");
}

KasX::Compiler::KasXCompiler::~KasXCompiler() { CORE_TRACE("Compiler Terminated"); }
