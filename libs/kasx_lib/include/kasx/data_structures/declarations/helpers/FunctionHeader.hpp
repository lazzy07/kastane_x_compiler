/*
* File name: FunctionHeader.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-19 17:57:02
// Date modified: 2026-03-20 15:43:50
* ------
*/
#pragma once

#include <string>
#include <vector>

#include "Parameter.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Declarations::Helpers {
struct FunctionHeader : public Traceable {
  std::string name;                   ///< function name
  std::vector<Parameter> parameters;  ///< Parameters used in the function header

  FunctionHeader(std::string name, Debug::DomainFileTrace trace) : Traceable(trace), name(std::move(name)) {}
};
}  // namespace KasX::Compiler::DataStructures::Declarations::Helpers
