/*
* File name: CompiledArgument.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 12:45:58
// Date modified: 2025-12-14 13:13:51
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
  int execution_type;
  std::string filePath;
};
}  // namespace KasX::App::CLI
