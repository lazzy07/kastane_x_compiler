/*
 * File name: DomainTests.cpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-10-16 22:27:43
 * Date modified: 2026-10-16 22:27:43
 * ------
 */

#include <gtest/gtest.h>

#include <algorithm>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <kasx/KasXCompiler.hpp>
#include <kasx/io/FileHandler.hpp>
#include <sstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

static std::vector<fs::path> collectDomainFiles(const fs::path& dir) {
  std::vector<fs::path> files;
  if (!fs::exists(dir) || !fs::is_directory(dir)) {
    return files;
  }
  for (const auto& entry : fs::directory_iterator(dir)) {
    if (entry.is_regular_file() && entry.path().extension() == ".txt") {
      files.push_back(entry.path());
    }
  }
  // directory_iterator order is unspecified, so sort for stable test order
  std::sort(files.begin(), files.end());
  return files;
}

class DomainTest : public ::testing::TestWithParam<fs::path> {};

TEST_P(DomainTest, DomainCompiles) {
  const fs::path& path = GetParam();

  std::ifstream domainFileStream(path);
  ASSERT_TRUE(domainFileStream.is_open()) << "Could not open domainfile: " << path;

  std::stringstream buffer;
  buffer << domainFileStream.rdbuf();

  EXPECT_FALSE(buffer.str().empty()) << path << " is empty";

  auto* fileHandler = new KasX::Compiler::IO::FileHandler();

  KasX::DomainData domainData = fileHandler->openProblemFile(path);

  auto* compiler = new KasX::Compiler::KasXCompiler();

  compiler->compile(std::move(domainData), {});
  const auto& diagnosticEngine = compiler->getDiagnosticEngineRef();
  size_t errorCount = diagnosticEngine.getErrorCount();

  ASSERT_EQ(errorCount, 0);
}

static std::string getDomainName(const ::testing::TestParamInfo<fs::path>& domainFilePath) {
  std::string name = domainFilePath.param.stem().string();
  for (char& character : name) {
    if (!std::isalnum(static_cast<unsigned char>(character))) {
      character = '_';
    }
  }
  return name;
}

INSTANTIATE_TEST_SUITE_P(DomainTests, DomainTest,
                         ::testing::ValuesIn(collectDomainFiles(std::string(KASX_TEST_DATA_DIR) + "/problems")), getDomainName);

// Avoiding failiure if the directory is empty or missing during discovery
GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(DomainTest);
