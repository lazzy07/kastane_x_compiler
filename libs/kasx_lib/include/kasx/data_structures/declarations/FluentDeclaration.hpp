/*
* File name: FluentDeclaration.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 17:47:04
// Date modified: 2026-03-20 15:44:23
* ------
*/
#pragma once

#include <utility>

#include "Declaration.hpp"
#include "TypeDeclaration.hpp"
#include "helpers/FunctionHeader.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
/**
 * @class FluentDeclaration
 * @brief Information and relationships about the Fluent Declaration
 *
 */
struct FluentDeclaration : public Declaration {
  Helpers::FunctionHeader functionHeader;  ///< Data related to function header, params & name
  TypeDeclaration* dataType;               ///< Datatype of the fluent eg: fluent(): dataType

  FluentDeclaration(std::string name, Helpers::FunctionHeader header, TypeDeclaration* dataType, Debug::DomainFileTrace trace)
      : Declaration(std::move(name), DECLARATION_TYPES::FLUENT_DECL, trace),
        functionHeader(std::move(header)),
        dataType(dataType) {}
};
}  // namespace KasX::Compiler::DataStructures::Declarations
