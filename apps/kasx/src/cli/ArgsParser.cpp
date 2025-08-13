#include "ArgsParser.hpp"

#include <Log.hpp>
#include <string>

#include "../core/VersionPrinter.hpp"
#include "ArgsParser.hpp"

KasX::App::CLI::ArgsParser::ArgsParser() { CORE_TRACE("Argument Parser Initialized"); }

KasX::App::CLI::ArgsParser::~ArgsParser() { CORE_TRACE("Argument Parser Terminated"); }

KasX::App::CLI::CompiledArgument KasX::App::CLI::ArgsParser::ParseArguments(int argc,
                                                                            char *argv[]) {
  // Return type that the ArgsHandler interpreted.
  CompiledArgument ret;

  KasX::App::Core::EXECUTION_TYPE execType = KasX::App::Core::EXECUTION_TYPE::UNKNOWN;

  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];

    if (arg == "-v" || arg == "--version") {
      CORE_TRACE("Version argument recieved: {}", arg);
      // Immediatly return, no need to check other arguments
      ret.execution_type = (int)KasX::App::Core::EXECUTION_TYPE::PRINT_VERSION;
      return ret;
    } else {
      if (i == 1) {
        CORE_TRACE("Unknown Argument as the 1st argument, must be the Problem file: {}", arg);
        // This must be the file to be compiled, since the 1st argument that application recieved
        // that cannot be handled above.
        ret.execution_type = (int)KasX::App::Core::EXECUTION_TYPE::COMPILE_FILE;
        ret.filePath = arg;
      } else {
        // Unknown argument found, which is not the first argument recieved. Must be an error!
        CORE_ERROR("Unknown argument found, but not as the 1st argument: {}", arg);
      }
    }
  }

  return ret;
}