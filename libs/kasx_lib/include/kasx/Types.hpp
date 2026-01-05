/*
* File name: Types.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-14 12:57:38
// Date modified: 2025-12-14 12:57:50
* ------
*/

#pragma once

#include <filesystem>
#include <fstream>

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
using declaration_id = uint16_t;

using linetrace_data = size_t;

/**
 * @brief number value data-type used in the planner
 */
using number_value = float;

/**
 * @class DomainData
 * @brief Domain Data is passed into the compiler when the application is presented with a problem file
 */
struct DomainData {
  std::string domainName;    ///< Domain name (interpreted from the filename)
  std::ifstream fileStream;  ///<  Content of the problem file as a filestream
  Path path;                 ///<  Path of the problem file
};
}  // namespace KasX
