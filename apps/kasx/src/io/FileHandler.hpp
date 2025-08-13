#pragma once

#include <filesystem>
#include <fstream>
#include <memory>

namespace KasX::App::IO {
class FileHandler {
 public:
  FileHandler();
  ~FileHandler();

  std::unique_ptr<std::ifstream> OpenProblemFile(const std::string &filePath);
  std::filesystem::path ExecutableDir();
};
}  // namespace KasX::App::IO