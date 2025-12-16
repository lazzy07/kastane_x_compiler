/*
* File name: DeclarationTypes.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-15 17:50:43
// Date modified: 2025-12-15 17:53:09
* ------
*/

#include <cstdint>
namespace KasX::Compiler::DataStructures::Declarations {
enum class DECLARATION_TYPES : std::uint8_t { TYPE_DECL, ENTITY_DECL, FLUENT_DECL, ACTION_DECL, TRIGGER_DECL, UTILITY_DECL };
}
