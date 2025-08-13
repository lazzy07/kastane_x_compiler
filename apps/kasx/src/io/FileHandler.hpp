#pragma once

#include <filesystem>
#include <kasx/Types.hpp>

namespace KasX::App::IO {
class FileHandler {
 public:
  FileHandler();
  ~FileHandler();

  DomainData OpenProblemFile(const KasX::Path &filePath);
  KasX::Path ExecutableDir();
};
}  // namespace KasX::App::IO