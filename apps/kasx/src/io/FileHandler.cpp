/*
* File name: FileHandler.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-05 22:36:58
// Date modified: 2025-12-14 12:58:07
* ------
*/

#include "FileHandler.hpp"

#include <Log.hpp>
#include <filesystem>

KasX::App::IO::FileHandler::FileHandler() { CORE_TRACE("FileHandler Initialized"); }

KasX::App::IO::FileHandler::~FileHandler() { CORE_TRACE("FileHandle Terminated"); }

KasX::DomainData KasX::App::IO::FileHandler::openProblemFile(const KasX::Path& filePath) {
  std::ifstream file(filePath);

  if (!file.is_open()) {
    CLI_ERROR("Cannot open file: {}", filePath.string());
    return {};
  }

  if (file.bad()) {
    CLI_ERROR("Unrecoverable error opening file: {}", filePath.string());
    return {};
  }

  std::string domainName = std::filesystem::path(filePath).stem().string();

  return {std::move(domainName), std::move(file), filePath};
}

std::filesystem::path KasX::App::IO::FileHandler::executableDir() {
#if defined(_WIN32)
  wchar_t buf[MAX_PATH];
  DWORD len = GetModuleFileNameW(nullptr, buf, MAX_PATH);
  return std::filesystem::path(buf, buf + len).parent_path();
#elif defined(__APPLE__)
  uint32_t size = 0;
  _NSGetExecutablePath(nullptr, &size);
  std::vector<char> buf(size);
  _NSGetExecutablePath(buf.data(), &size);
  return std::filesystem::path(buf.data()).parent_path();
#else  // Linux, *BSD with /proc
  std::vector<char> buf(4096);
  ssize_t len = readlink("/proc/self/exe", buf.data(), buf.size() - 1);
  if (len > 0) buf[len] = '\0';
  return std::filesystem::path(buf.data()).parent_path();
#endif
}
