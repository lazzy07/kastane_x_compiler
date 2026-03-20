/*
* File name: GroundedFluent.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2026-03-20 16:13:29
// Date modified: 2026-03-20 17:45:58
* ------
*/

#include <kasx/data_structures/grounded/GroundedFluent.hpp>
#include <sstream>
#include <vector>

#include "../core/services/IDHandler.hpp"
#include "Log.hpp"
#include "kasx/data_structures/declarations/EntityDeclaration.hpp"
#include "kasx/data_structures/declarations/FluentDeclaration.hpp"

namespace KasX::Compiler::DataStructures::Grounded {
GroundedFluent::GroundedFluent(DataStructures::Declarations::FluentDeclaration* fluent,
                               const std::vector<DataStructures::Declarations::EntityDeclaration*>& entities) {
  this->id = Core::Services::IDHandler::GetID();
  this->parent = fluent;
  this->entities = entities;
  this->type = this->parent->dataType;
  this->name = generateName(this->parent->name);
  CLI_TRACE("Grounded fluent created: {}", this->name);
}

std::string GroundedFluent::generateName(const std::string& partialName) {
  std::ostringstream nameStream;

  nameStream << partialName << "(";

  for (int i = 0; i < this->entities.size(); i++) {
    nameStream << this->entities.at(i)->name;

    if (i < this->entities.size() - 1) {
      nameStream << ",";
    }
  }

  nameStream << ")";

  return nameStream.str();
}
}  // namespace KasX::Compiler::DataStructures::Grounded
