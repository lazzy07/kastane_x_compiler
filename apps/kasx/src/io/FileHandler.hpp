#pragma once

#include <kasx/Types.hpp>

namespace KasX::App::IO {
class FileHandler {
 public:
  FileHandler();
  ~FileHandler();

  DomainData openProblemFile(const KasX::Path& filePath);
  KasX::Path executableDir();
};
}  // namespace KasX::App::IO
