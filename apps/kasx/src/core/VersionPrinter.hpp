/*
* File name: VersionPrinter.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 13:09:10
// Date modified: 2025-12-14 13:09:12
* ------
*/

#pragma once
#include <string>

namespace KasX::App::Core {
/**
 * @class VersionPrinter
 * @brief Prints the version info and the logo
 * Used to print version of the project, logo etc.
 */
class VersionPrinter {
 public:
  /**
   * @brief Generates the version details including the logo.
   */
  static void printVersionDetails();

 private:
  static std::string getLogo();
};
}  // namespace KasX::App::Core
