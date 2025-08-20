#include <Log.hpp>
#include <lazlogger/LoggerManager.hpp>

#include "./cli/ArgsParser.hpp"
#include "./core/ApplicationManager.hpp"

int main(int argc, char *argv[]) {
  auto logger = LazLogger::LoggerManager();
  logger.Initialize({.core = {.name = CORE_LOGGER_NAME, .file = "log/core/kasx_compiler.txt"},
                     .cli = {.name = CLI_LOGGER_NAME, .file = "log/cli/kasx_log.txt"}});

  CORE_TRACE("Logger Initialized");
  CORE_TRACE("Application Started");

  auto argsParser = KasX::App::CLI::ArgsParser();

  KasX::App::CLI::CompiledArgument arguments = argsParser.ParseArguments(argc, argv);

  auto *app = new KasX::App::Core::ApplicationManager(arguments);

  app->Execute();

  delete app;
  CORE_TRACE("Main Appliaction Terminated");
  logger.Terminate();
  return 0;
}