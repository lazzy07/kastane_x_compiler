/*
* File name: ApplicationManager.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 13:11:49
// Date modified: 2025-12-14 13:13:40
* ------
*/

#include "ApplicationManager.hpp"

#include <Log.hpp>
#include <kasx/KasXCompiler.hpp>
#include <kasx/Types.hpp>

#include "../io/FileHandler.hpp"
#include "Execution.hpp"
#include "VersionPrinter.hpp"

KasX::App::Core::ApplicationManager::ApplicationManager(KasX::App::CLI::CompiledArgument arguments)
    : m_Arguments(std::move(arguments)) {
  CORE_TRACE("Application Manager Created");

  KasX::Compiler::KasXCompiler::InitLogger();
}

KasX::App::Core::ApplicationManager::~ApplicationManager() { CORE_TRACE("Application Manager Terminated"); }

void KasX::App::Core::ApplicationManager::execute() {
  int type = m_Arguments.execution_type;

  if (type & static_cast<int>(KasX::App::Core::EXECUTION_TYPE::PRINT_VERSION)) {
    CORE_TRACE("Executing Version Printer");
    VersionPrinter::printVersionDetails();
  } else {
    if (type & static_cast<int>(KasX::App::Core::EXECUTION_TYPE::COMPILE_FILE)) {
      CORE_TRACE("Executing File Parsing");
      std::string filePath = m_Arguments.filePath;

      auto* fileHandler = new KasX::App::IO::FileHandler();

      KasX::DomainData domainData = fileHandler->openProblemFile(filePath);

      auto* compiler = new KasX::Compiler::KasXCompiler();

      compiler->compile(std::move(domainData), {});

      delete compiler;
      delete fileHandler;
      return;
    }

    CORE_ERROR("TODO:: Handle Unknown/No Arguments");
  }
}
