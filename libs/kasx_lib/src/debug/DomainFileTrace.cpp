/*
 * File name: DomainFileTrace.cpp
 * Project: KasX Compiler
 * Author: Lasantha M Senanayake
 * Date created: 2026-09-29 12:27:04
 * Date modified: 2026-09-29 12:27:04
 * ------
 */

#include "kasx/debug/DomainFileTrace.hpp"

#include "../visitors/AntlrSafeRuntime.hpp"

namespace KasX::Compiler::Debug {
DomainFileTrace DomainFileTrace::GetTraceData(antlr4::Token* start, antlr4::Token* stop) {
  if (start == nullptr) {
    return DomainFileTrace::GetDefaultFileTrace();
  }
  if (stop == nullptr || stop->getStopIndex() < start->getStartIndex()) {
    stop = start;  // empty rule or error recovery left no stop token
  }

  DomainFileTrace trace(
      {static_cast<linetrace_data>(start->getLine()), static_cast<linetrace_data>(start->getCharPositionInLine())},
      {static_cast<linetrace_data>(stop->getLine()),
       static_cast<linetrace_data>(stop->getCharPositionInLine() + stop->getText().size())});

  trace.startIndex = start->getStartIndex();
  trace.stopIndex = stop->getStopIndex();
  return trace;
}
}  // namespace KasX::Compiler::Debug
