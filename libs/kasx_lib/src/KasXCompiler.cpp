/*
* File name: KasXCompiler.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 01:45:16
// Date modified: 2025-12-14 13:27:20
* ------
*/

#include <kasx/Domain.hpp>
#include <kasx/KasXCompiler.hpp>
#include <lazlogger/LoggerManager.hpp>

namespace KasX::Compiler {
KasXCompiler::KasXCompiler() { CORE_TRACE("Compiler Initialized"); }

KasXCompiler::~KasXCompiler() { CORE_TRACE("Compiler Terminated"); }

void KasXCompiler::compile(DomainData data, COMPILER_OPTIONS options) {
  if (data.domainName.empty()) {
    CLI_ERROR("Cannot compile undefined domain");
    return;
  }

  CLI_INFO("Domain found and, Started compiling {} : {}", data.domainName, data.path.string());

  KasX::Compiler::Core::Domain domain(data);
  domain.initVisitor();
}

void KasXCompiler::InitLogger() {
  if (s_Logger) {
    CORE_ERROR("Logger already being initialized");
  }

  s_Logger = std::make_unique<LazLogger::LoggerManager>();

  s_Logger->Initialize({.core = {.name = CORE_LOGGER_NAME, .file = "log/core/kasx_compiler_lib.txt"},
                        .cli = {.name = CLI_LOGGER_NAME, .file = "log/cli/kasx_log_lib.txt"}});
}
}  // namespace KasX::Compiler
