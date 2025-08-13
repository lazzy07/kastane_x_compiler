#include "ApplicationManager.hpp"

#include <Log.hpp>
#include <kasx/KasXCompiler.hpp>
#include <kasx/Types.hpp>

#include "../io/FileHandler.hpp"
#include "Execution.hpp"
#include "VersionPrinter.hpp"

KasX::App::Core::ApplicationManager::ApplicationManager(KasX::App::CLI::CompiledArgument arguments)
    : m_Arguments(arguments) {
  CORE_TRACE("Application Manager Created");

  KasX::Compiler::KasXCompiler::InitLogger();
}

KasX::App::Core::ApplicationManager::~ApplicationManager() {
  CORE_TRACE("Application Manager Terminated");
}

void KasX::App::Core::ApplicationManager::Execute() {
  int type = m_Arguments.execution_type;

  if (type & (int)KasX::App::Core::EXECUTION_TYPE::PRINT_VERSION) {
    CORE_TRACE("Executing Version Printer");
    VersionPrinter::printVersionDetails();
    return;
  } else {
    if (type & (int)KasX::App::Core::EXECUTION_TYPE::COMPILE_FILE) {
      CORE_TRACE("Executing File Parsing");
      std::string filePath = m_Arguments.filePath;

      KasX::App::IO::FileHandler *fileHandler = new KasX::App::IO::FileHandler();

      KasX::DomainData domainData = fileHandler->OpenProblemFile(filePath);

      KasX::Compiler::KasXCompiler *compiler = new KasX::Compiler::KasXCompiler();

      compiler->Compile(std::move(domainData), {});

      delete compiler;
      delete fileHandler;
      return;
    }

    CORE_ERROR("TODO:: Handle Unknown/No Arguments");
  }
}
