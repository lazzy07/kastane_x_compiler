/*
* File name: Parameter.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-20 12:48:46
// Date modified: 2026-03-20 14:36:16
* ------
*/

#include <kasx/data_structures/declarations/helpers/Parameter.hpp>

#include "Log.hpp"
#include "kasx/data_structures/declarations/Declaration.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Declarations::Helpers {
Parameter::Parameter(std::string name, Debug::DomainFileTrace trace) : Traceable(trace), name(std::move(name)) {
  CLI_TRACE("Parameter created: {}", this->name);
}
}  // namespace KasX::Compiler::DataStructures::Declarations::Helpers
