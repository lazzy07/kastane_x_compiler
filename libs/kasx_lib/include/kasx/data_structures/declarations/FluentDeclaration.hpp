/*
* File name: FluentDeclaration.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 17:47:04
// Date modified: 2025-12-15 22:29:30
* ------
*/

#include "./helpers/Parameter.hpp"
#include "Declaration.hpp"
#include "TypeDeclaration.hpp"

namespace KasX::Compiler::DataStructures::Declarations {
/**
 * @class FluentDeclaration
 * @brief Information and relationships about the Fluent Declaration
 *
 */
struct FluentDeclaration : public Declaration {
  std::vector<Helpers::Parameter> parameters;  ///< Parameter data of the fluent
  TypeDeclaration* dataType;                   ///< Datatype of the fluent eg: fluent(): dataType
};
}  // namespace KasX::Compiler::DataStructures::Declarations
