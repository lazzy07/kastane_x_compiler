#include <Log.hpp>
#include <kasx/Domain.hpp>

#include "kasx/Types.hpp"

namespace KasX::Compiler::Core {
Domain::Domain(DomainData& data) { CLI_TRACE("Domain initialized"); };

Domain::~Domain() { CLI_TRACE("Domain deleted"); };

void Domain::initVisitor() { CLI_TRACE("Hello from the visitor"); }
}  // namespace KasX::Compiler::Core
