#pragma once

/**
 * This will select the execution type of the compiler, mainly if you pass a filename it will be
 * compiled into corresponding data-strcutures.
 */
namespace KasX::App::Core {
enum class EXECUTION_TYPE { UNKNOWN = 0, PRINT_VERSION = 1 << 0, COMPILE_FILE = 1 << 1 };
}