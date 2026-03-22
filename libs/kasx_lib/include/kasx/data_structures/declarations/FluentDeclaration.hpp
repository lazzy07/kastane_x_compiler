/*
* File name: FluentDeclaration.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 17:47:04
// Date modified: 2026-03-20 23:47:09
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
  TypeDeclaration* dataType;               ///< Datatype of the fluent eg: fluent(): dataType
  Helpers::FunctionHeader functionHeader;  ///< Data related to function header, params & name

  /**
   * @brief Fluent declaration constructor
   *
   * @param name Fluent name
   * @param header Fluent function header
   * @param dataType Data type of the fluent
   * @param trace Debug file trace
   */
  FluentDeclaration(std::string name, Helpers::FunctionHeader header, TypeDeclaration* dataType, Debug::DomainFileTrace trace)
      : Declaration(std::move(name), DECLARATION_TYPES::FLUENT_DECL, trace),
        functionHeader(std::move(header)),
        dataType(dataType) {}
};
}  // namespace KasX::Compiler::DataStructures::Declarations
