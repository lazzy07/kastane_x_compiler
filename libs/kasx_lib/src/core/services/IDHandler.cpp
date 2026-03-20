/*
* File name: IDHandler.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-19 12:32:03
// Date modified: 2026-03-19 12:36:28
* ------
*/

#include "IDHandler.hpp"

#include "kasx/Types.hpp"

namespace KasX::Compiler::Core::Services {
KasX::declaration_id IDHandler::currentLastID = -1;

KasX::declaration_id IDHandler::GetID() { return ++currentLastID; }
}  // namespace KasX::Compiler::Core::Services
