/*
 * File name: GroundedTrigger.hpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-03 23:57:32
 * Date modified: 2026-09-03 23:57:32
 * ------
 */

#include "kasx/Types.hpp"
#include "kasx/data_structures/declarations/TypeDeclaration.hpp"
#include "kasx/data_structures/expressions/Expression.hpp"

namespace KasX::Compiler::DataStructures::Grounded {
struct GroundedTrigger {
  declaration_id id;                                                     ///< Grounded actions ID
  Compiler::DataStructures::Declarations::TypeDeclaration* declaration;  ///< Parent action declaration pointer

  Expressions::ExpressionPtr precondition;  ///< Precondition of the action
  Expressions::ExpressionPtr effect;        ///< Effect of the action
};
}  // namespace KasX::Compiler::DataStructures::Grounded
