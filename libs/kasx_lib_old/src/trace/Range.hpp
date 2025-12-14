/**
 * @file Range.hpp 
 * @author Lasantha M Senanayake (222lasantha@gmail.com)
 * @brief Keep information about the trace of the source file for debugging
 * @version 0.1
 * @date 2025-09-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include <kasx/Types.hpp>

namespace KasX::Compiler::Trace{
  struct Position{
    linetrace_data line;
    linetrace_data character;
  };
  
  struct Range{
    Position start;
    Position end;
  };
}  // namespace KasX::Compiler::Trace