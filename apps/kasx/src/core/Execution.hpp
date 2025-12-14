/*
* File name: Execution.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 12:50:41
// Date modified: 2025-12-14 13:13:26
* ------
*/

#pragma once

namespace KasX::App::Core {
/**
 * This will select the execution type of the compiler, mainly if you pass a filename it will be
 * compiled into corresponding data-strcutures.
 */
enum class EXECUTION_TYPE { UNKNOWN = 0, PRINT_VERSION = 1 << 0, COMPILE_FILE = 1 << 1 };
}  // namespace KasX::App::Core
