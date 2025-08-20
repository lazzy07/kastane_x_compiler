#pragma once

#include <filesystem>
#include <fstream>
#include <memory>

namespace KasX {

/**
 * Filepath: Represents a filesystem path and provides a comprehensive interface for constructing,
 * modifying, and querying paths
 */
using Path = std::filesystem::path;

/**
 * @enum COMPILER_OPTIONS is an enumeration intended to define compiler options.
 */
enum COMPILER_OPTIONS {

};

/**
 * @brief Datatype used to define id # of data-structure tables
 *
 */
using definition_id = uint16_t;

using linetrace_data = size_t;

struct FileTrace {
  linetrace_data lineNumber;
  linetrace_data columnNumber;
};

/**
 * Domain Data is passed into the compiler when the application is presented with a problem file
 */
struct DomainData {
  std::string domainName;    // Domain name (interpreted from the filename)
  std::ifstream fileStream;  //  Content of the problem file as a filestream
  Path path;                 //  Path of the problem file
};
}  // namespace KasX