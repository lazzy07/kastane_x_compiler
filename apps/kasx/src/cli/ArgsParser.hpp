/*
* File name: ArgsParser.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 13:15:37
// Date modified: 2025-12-14 13:16:05
* ------
*/

#pragma once
#include "CompiledArgument.hpp"

namespace KasX::App::CLI {
/**
 * @class ArgsParser
 * @brief Functionality to parse command-line arguments.
 *
 */
class ArgsParser {
 public:
  ArgsParser();
  ~ArgsParser();
  /**
   * @brief Function that will parse the arguments.
   *
   *  Arguments passed using argc and argv to the executable will be parsed by this.
   *
   * @param argc Arguments coming from the main.cpp
   * @param argv Arugments coming from the main.cpp
   * @return Processed data about the current execution mode
   */
  CompiledArgument parseArguments(int argc, char* argv[]);
};
}  // namespace KasX::App::CLI
