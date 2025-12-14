/*
* File name: FileHandler.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 12:56:05
// Date modified: 2025-12-14 12:59:42
* ------
*/

#pragma once

#include <kasx/Types.hpp>

namespace KasX::App::IO {
class FileHandler {
 public:
  FileHandler();
  ~FileHandler();

  /**
   * @brief Reads and returns required data about the problem (Domain) file.
   *
   * Used to read and get the domain data related to the current domain.
   *
   * @param filePath File path of the domain text/code
   * @return Data related to the domain.
   */
  DomainData openProblemFile(const KasX::Path& filePath);

  /**
   * @brief Finds the path of the current executable
   */
  KasX::Path executableDir();
};
}  // namespace KasX::App::IO
