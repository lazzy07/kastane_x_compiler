#include "FileHandler.hpp"

#include <Log.hpp>

KasX::App::IO::FileHandler::FileHandler() { CORE_TRACE("FileHandler Initialized"); }

KasX::App::IO::FileHandler::~FileHandler() { CORE_TRACE("FileHandle Terminated"); }

std::unique_ptr<std::ifstream> KasX::App::IO::FileHandler::OpenProblemFile(
    const std::string &filePath) {
  auto file = std::make_unique<std::ifstream>(filePath);

  if (!file->is_open()) {
    CLI_ERROR("Cannot open file: {}", filePath);
  }

  if (file->bad()) {
    CLI_ERROR("Unrecoverable error opening file: {}", filePath);
  }

  return file;
}

std::filesystem::path KasX::App::IO::FileHandler::ExecutableDir() {
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
