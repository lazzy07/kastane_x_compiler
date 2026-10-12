/*
 * File name: DeclarationTests.cpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-10-12 15:08:16
 * Date modified: 2026-10-12 15:08:16
 * ------
 */

#include <gtest/gtest.h>

#include <kasx/io/FileHandler.hpp>
#include <string>

#include "kasx/KasXCompiler.hpp"

class DeclarationTests : public testing::Test {
 public:
  void setDomainFile(const std::string& domainFilePath) { m_DomainFilePath = domainFilePath; }

  size_t runTestAndGetErrorCount() {
    auto* fileHandler = new KasX::Compiler::IO::FileHandler();

    KasX::DomainData domainData = fileHandler->openProblemFile(m_DomainFilePath);

    auto* compiler = new KasX::Compiler::KasXCompiler();

    compiler->compile(std::move(domainData), {});
    const auto& diagnosticEngine = compiler->getDiagnosticEngineRef();
    return diagnosticEngine.getErrorCount();
  }

 private:
  std::string m_DomainFilePath;
};

TEST_F(DeclarationTests, ParamNotDeclaredTest) {
  setDomainFile("tests/modules/declarations/param_not_declared.sabre");
  ASSERT_EQ(runTestAndGetErrorCount(), 0);
}
