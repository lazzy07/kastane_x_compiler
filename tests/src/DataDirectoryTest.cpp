/*
 * File name: DataDirectoryTest.cpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-27 09:22:02
 * Date modified: 2026-09-27 09:22:02
 * ------
 */

#include <gtest/gtest.h>

#include <filesystem>

TEST(TestEnvironmentTests, IsMacroDefined) {
#ifdef KASX_TEST_DATA_DIR
  SUCCEED();
#else
  FAIL() << "KASX_TEST_DATA_DIR is not defined. Add it via target_compile_definitions to the test suite"
#endif
}

TEST(TestEnvironmentTests, TestDataDirExists) {
#ifdef KASX_TEST_DATA_DIR
  const std::filesystem::path dir{KASX_TEST_DATA_DIR};
  ASSERT_TRUE(std::filesystem::is_directory(dir)) << "Not a directory: " << dir;
#else
  GTEST_SKIP() << "KASX_TEST_DATA_DIR is not defined";
#endif
}
