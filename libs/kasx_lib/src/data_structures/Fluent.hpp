#pragma once

#include "Definition.hpp"
#include "kasx/Types.hpp"
namespace KasX::Compiler::DataStructures {
  struct Fluent : public Definition{
    definition_id type;
  };
}