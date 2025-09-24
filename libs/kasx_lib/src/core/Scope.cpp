#include "Scope.hpp"

#include <Log.hpp>
#include <memory>
#include <vector>

#include "kasx/Types.hpp"

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
  // username - lazzy07 TODO: Handle the error
  if (m_Type != SCOPE_TYPES::GLOBAL) {
    CLI_ERROR("Declrations must be inside the global scope");
    return;
  }

  // username - lazzy07 TODO: Handle the error
  if (GetDefinition(name) != nullptr) {
    CLI_ERROR("Definition with the same name already exists: {}", name);
    return;
  }

  m_Definitions.emplace(name, std::move(data));
  CLI_TRACE("Adding definition {} completed", name);
}

std::vector<KasX::definition_id> KasX::Compiler::Core::Scope::GetParentIDs(
    const std::string &name, const std::vector<std::string> &parents) {
  std::vector<definition_id> parentIDs;

  for (std::string parent : parents) {
    // username - lazzy07 TODO: Handle the error

    DefinitionData *parentDef = GetDefinition(parent);

    if (parentDef == nullptr) {
      CORE_ERROR("For the type: {} parent {}, does not exist", name, parent);
      return {};
    }

    parentIDs.push_back(parentDef->id);
  }

  return parentIDs;
}

void KasX::Compiler::Core::Scope::InitNewType(const std::string &name,
                                              const KasX::Compiler::Trace::Range &range,
                                              const std::vector<std::string> &parents) {
  CORE_TRACE("New type initialization started: {}", name);

  std::vector<KasX::definition_id> parentIDs = GetParentIDs(name, parents);

  // If the function continues here, all the parents are found, no errors.
  definition_id typeID = this->m_Types.size();

  // Creating definition data for the type declaration
  auto definitionData = std::make_unique<DefinitionData>();
  definitionData->id = typeID;
  definitionData->type = KasX::Compiler::DataStructures::DEFINITION_TYPES::TYPE_DEFINITION;

  auto type = std::make_unique<KasX::Compiler::DataStructures::Type>();

  type->id = typeID;
  type->parents = parentIDs;
  type->trace = range;
  type->name = name;
}

void KasX::Compiler::Core::Scope::InitNewEntity(const std::string &name,
                                                const KasX::Compiler::Trace::Range &range,
                                                const std::vector<std::string> &parents) {}