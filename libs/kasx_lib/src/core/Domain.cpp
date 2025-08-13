#include "Domain.hpp"

#include <Log.hpp>

KasX::Compiler::Core::Domain::Domain(DomainData &data) {
  CORE_TRACE("Domain Initialized");

  m_DomainData = std::make_unique<DomainData>(std::move(data));
}

KasX::Compiler::Core::Domain::~Domain() { CORE_TRACE("Domain Terminated"); }