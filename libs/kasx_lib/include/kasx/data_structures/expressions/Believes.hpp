/*
* File name: Believes.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-08-20 12:00:00
* ------
*/

#pragma once

#include <string>
#include <utility>

#include "Expression.hpp"
#include "Log.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
/**
 * @class Believes
 * @brief Expression representation of an epistemic belief statement, eg: believes(Merchant, at(Tom) = ?)
 *
 * Mirrors Sabre's `Epistemic` expression (edu.uky.cs.nil.sabre.logic.Epistemic): `character` must resolve to an entity of
 * type `character`, and `argument` is the logical expression the character is believed to hold (a fluent reference, a
 * comparison/assignment involving one, or even another Believes expression for nested beliefs).
 *
 */
struct Believes : public Expression {
  std::string character;  ///< Identifier of the character that holds the belief, eg: Merchant
  ExpressionPtr argument;  ///< Logical expression the character holds a belief about, eg: at(Tom) = ?

  /**
   * @brief Believes expression constructor
   *
   * @param character Identifier of the character that holds the belief
   * @param argument Logical expression the character holds a belief about
   * @param trace Debug file trace
   */
  Believes(const std::string& character, ExpressionPtr argument, Debug::DomainFileTrace trace)
      : Expression(false, EXPRESSION_TYPES::BELIEVES_OPERATION, generateName(character, argument), trace),
        character(character),
        argument(std::move(argument)) {
    CLI_TRACE("Believes expression created: {}", name);
  }

 private:
  static std::string generateName(const std::string& character, const ExpressionPtr& argument) {
    return "believes(" + character + "," + (argument != nullptr ? argument->name : "") + ")";
  }
};
}  // namespace KasX::Compiler::DataStructures::Expressions
