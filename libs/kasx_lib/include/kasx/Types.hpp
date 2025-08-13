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
 * Domain Data is passed into the compiler when the application is presented with a problem file
 */
struct DomainData {
  std::string domainName;    // Domain name (interpreted from the filename)
  std::ifstream fileStream;  //  Content of the problem file as a filestream
  Path path;                 //  Path of the problem file
};
}  // namespace KasX