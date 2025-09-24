#include "Scope.hpp"

#include <Log.hpp>

KasX::Compiler::Core::Scope::Scope(std::string name, SCOPE_TYPES type,
                                   std::unique_ptr<Scope> parent)
    : m_Name(std::move(name)), m_Type(type), m_Parent(std::move(parent)) {
  CORE_TRACE("Scope initialized {}", m_Name);
}

KasX::Compiler::Core::Scope::~Scope() { CORE_TRACE("Scope Destroyed {}", m_Name); }

KasX::Compiler::Core::DefinitionData *KasX::Compiler::Core::Scope::GetDefinition(
    const std::string &name) {
  CLI_TRACE("Checking if definition already exists: {}", name);

  auto dataPtr = m_Definitions.find(name);
  if (dataPtr == m_Definitions.end()) {
    CLI_TRACE("Definition {} - does not exist", name);
    return nullptr;
  }

  CLI_TRACE("Definition: {} - already exists", name);
  return dataPtr->second.get();
}

void KasX::Compiler::Core::Scope::AddDefinition(const std::string &name,
                                                std::unique_ptr<DefinitionData> data) {
  if (m_Definitions.find(name) == m_Definitions.end()) {
    CORE_TRACE("Adding new definition: {} with ID: {}", name, data->id);
    m_Definitions.emplace(name, std::move(data));
  } else {
    CORE_TRACE("Adding new definition failed, already exists: {}", name);
  }
}

void KasX::Compiler::Core::Scope::InitNewType(const std::string &name,
                                              const KasX::Compiler::Trace::Range &range,
                                              const std::vector<std::string> &parents) {}

void KasX::Compiler::Core::Scope::InitNewEntity(const std::string &name,
                                                const KasX::Compiler::Trace::Range &range,
                                                const std::vector<std::string> &parents) {}