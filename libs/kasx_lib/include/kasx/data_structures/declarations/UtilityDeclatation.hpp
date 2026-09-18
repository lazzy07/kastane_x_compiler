/*
 * File name: UtilityDeclatation.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-03 23:34:49
 * Date modified: 2026-09-03 23:34:49
 * ------
 */

#pragma once

#include "kasx/core/scopes/Scope.hpp"
#include "kasx/data_structures/declarations/Declaration.hpp"
#include "kasx/data_structures/declarations/EntityDeclaration.hpp"
#include "kasx/data_structures/expressions/Expression.hpp"
#include "kasx/debug/DomainFileTrace.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
/**
 * @class UtilityDeclaration
 * @brief Declaration of a utility function (Scope for the utility and its evaluated expression can be found here)
 *
 */
struct UtilityDeclaration : public Declaration {
  Core::Scopes::Scope* scope;             ///< Utility scope
  Expressions::ExpressionPtr expression;  ///< Expression the utility evaluates to
  EntityDeclaration* entity;              ///< Entity that the utility function belongs to (null if this is for author)

  UtilityDeclaration(const std::string& name, Debug::DomainFileTrace fileTrace)
      : Declaration(name, DECLARATION_TYPES::UTILITY_DECL, fileTrace) {}
};
}  // namespace KasX::Compiler::DataStructures::Declarations
