/*
* File name: Value.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-04-10 15:47:17
// Date modified: 2026-08-17 23:36:29
* ------
*/
#pragma once

#include "../expressions/ExpressionTypes.hpp"
#include "Log.hpp"

namespace KasX::Compiler::DataStructures::Values {
/**
 * @brief Stores any type of value that KasX Compiler supports
 *
 * @tparam T Generic type
 * @param value Actual value to be stored
 */
template <typename T>

struct Value {
  Expressions::EXPRESSION_TYPES type;
  T value;

  Value(Expressions::EXPRESSION_TYPES type, T value) : type(type), value(value) { CLI_TRACE("New value created"); }

  /**
   * @brief Set the value
   *
   * @param value Value with the type T
   */
  void setValue(T value) { this->value = value; };

  /**
   * @brief Get the value with the correct type
   *
   * @return Returns the value as the type
   */
  [[nodiscard]] T getValue() const { return this->value; };
};
}  // namespace KasX::Compiler::DataStructures::Values
