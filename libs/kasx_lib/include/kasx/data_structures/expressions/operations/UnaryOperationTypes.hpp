/*
* File name: UnaryOperationTypes.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-04-10 15:04:38
// Date modified: 2026-08-19 14:21:50
* ------
*/

#pragma once

#include <cstdint>
namespace KasX::Compiler::DataStructures::Expressions {
enum class UNARY_OPERATION_TYPES : std::uint8_t { UNARY_NOT, UNARY_NEGATION };
}
