/*
* File name: ApplicationManager.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 13:11:52
// Date modified: 2025-12-14 13:11:55
* ------
*/

#pragma once

#include "../cli/CompiledArgument.hpp"

namespace KasX::App::Core {
/**
 * @class ApplicationManager
 * @brief Entrypoint to the compiler.
 *
 * This class manages the whole compiler application. The entrypoint to the compiler program.
 *
 */
class ApplicationManager {
 public:
  explicit ApplicationManager(KasX::App::CLI::CompiledArgument arguments);
  ~ApplicationManager();

  /**
   * @brief Command that executes the compiler.
   *
   * Call this function to execute the program. This funciton needs to be called in order to run the program. This will run the
   * program using the configuration passed into the constructor of this class ApplicationManager::ApplicationManager
   */
  void execute();

 private:
  KasX::App::CLI::CompiledArgument m_Arguments;
};
}  // namespace KasX::App::Core
