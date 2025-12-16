/*
* File name: CompiledArgument.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 12:45:58
// Date modified: 2025-12-15 21:54:10
* ------
*/

#pragma once

#include <string>

namespace KasX::App::CLI {
/**
 * @class CompiledArgument
 * @brief Explains what configuration does the compiler runs on.
 *
 * For this struct, execution type can be version printer, compilation etc.
 *
 */
struct CompiledArgument {
  int execution_type;    ///< Current execution type (print version, compile file etc.).
  std::string filePath;  ///< Filepath of the domain(problem) file.
};
}  // namespace KasX::App::CLI
