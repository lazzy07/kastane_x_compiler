/*
 * File name: Fluent.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-08-20 11:00:00
 * ------
 */

#pragma once

#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "Expression.hpp"
#include "Log.hpp"
#include "kasx/data_structures/grounded/GroundedFluent.hpp"

namespace KasX::Compiler::DataStructures::Expressions {
/**
 * @class Fluent
 * @brief Expression representation of a fluent reference, eg: path(Castle, Mountain), at(Aladdin)
 *
 */
struct Fluent : public Expression {
  std::string baseName;                      ///< Name of the fluent itself, without its arguments, eg: path
  std::vector<std::string> arguments;        ///< Identifier names of the arguments the fluent was called with.
  Grounded::GroundedFluent* groundedFluent;  ///< Grounded fluent that expression fluent based on

  /**
   * @brief Fluent expression constructor
   *
   * @param baseName Name of the fluent, eg: path
   * @param arguments Argument identifiers the fluent was called with, eg: [Castle, Mountain]
   * @param trace Debug file trace
   */
  Fluent(const std::string& baseName, std::vector<std::string> arguments, Debug::DomainFileTrace trace)
      : Expression(false, EXPRESSION_TYPES::FLUENT, generateName(baseName, arguments), trace),
        baseName(baseName),
        arguments(std::move(arguments)) {
    CLI_TRACE("Fluent expression created: {}", name);
  }

 private:
  static std::string generateName(const std::string& baseName, const std::vector<std::string>& arguments) {
    std::ostringstream nameStream;
    nameStream << baseName << "(";

    for (size_t i = 0; i < arguments.size(); i++) {
      nameStream << arguments.at(i);
      if (i < arguments.size() - 1) {
        nameStream << ",";
      }
    }

    nameStream << ")";
    return nameStream.str();
  }
};
}  // namespace KasX::Compiler::DataStructures::Expressions
