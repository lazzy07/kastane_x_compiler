#include "Scope.hpp"

#include <Log.hpp>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "GlobalScope.hpp"
#include "kasx/Types.hpp"

KasX::Compiler::Core::Scope::Scope(std::string name, SCOPE_TYPES type)
    : TraceableClass("Scope: " + name), m_Name(std::move(name)), m_Type(type) {
  CORE_TRACE("Scope initialized {}", m_Name);
}

KasX::Compiler::Core::Scope::~Scope() { CORE_TRACE("Scope Destroyed {}", m_Name); }

KasX::Compiler::Core::DeclarationData* KasX::Compiler::Core::Scope::getDefinition(const std::string& name) {
  TracePrint("Checking if definition already exists: {}", name);

  auto dataPtr = m_Definitions.find(name);
  if (dataPtr == m_Definitions.end()) {
    TracePrint("Definition Exists Check {} - does not exist", name);
    return nullptr;
  }

  TracePrint("Definition Exists Check: {} - already exists", name);
  return dataPtr->second.get();
}

void KasX::Compiler::Core::Scope::addDefinition(const std::string& name, std::unique_ptr<DeclarationData> data) {
  // username - lazzy07 TODO: Handle the error
  if (m_Type != SCOPE_TYPES::GLOBAL) {
    CLI_ERROR("Declarations must be inside the global scope");
    return;
  }

  // username - lazzy07 TODO: Handle the error
  if (getDefinition(name) != nullptr) {
    CLI_ERROR("Definition with the same name already exists: {}", name);
    return;
  }

  m_Definitions.emplace(name, std::move(data));
  TracePrint("Adding definition {} completed", name);
}

std::vector<KasX::declaration_id> KasX::Compiler::Core::Scope::getParentIDs(const std::string& name,
                                                                            const std::vector<std::string>& parents) {
  std::vector<declaration_id> parentIDs;

  for (std::string parent : parents) {
    // username - lazzy07 TODO: Handle the error

    DeclarationData* parentDef = getDefinition(parent);

    if (parentDef == nullptr) {
      CORE_ERROR("For the type: {} parent {}, does not exist", name, parent);
      return {};
    }

    if (parentDef->type != DataStructures::DECLARATION_TYPES::TYPE_DEFINITION) {
      CLI_ERROR("Parent/Type '{}' for '{}' does not exist as a type", parent, name);
      return {};
    }

    parentIDs.push_back(parentDef->id);
  }

  return parentIDs;
}

void KasX::Compiler::Core::Scope::initNewEntity(const std::string& name, const KasX::Compiler::Trace::Range& range,
                                                const std::vector<std::string>& types) {
  TracePrint("New entity initialization started: {}", name);

  if (m_Type != SCOPE_TYPES::GLOBAL) {
    CORE_ERROR("Entity declarations should be done only inside the global scope: {}", name);
    return;
  }

  // First check if the entity already exists or not
  if (getDefinition(name) != nullptr) {
    CLI_ERROR("Entity '{}' already exists as a definition", name);
    return;
  }

  declaration_id entityID = m_EntityDeclarations.size();

  if (types.size() > 0) {
    // Typename declaration is correct (size wise), has exactly one type
    auto typesVec = getParentIDs(name, types);

    auto definitionData = std::make_unique<DeclarationData>();
    definitionData->id = entityID;
    definitionData->type = DataStructures::DECLARATION_TYPES::ENTITY_DEFINITION;

    auto entity = std::make_unique<DataStructures::EntityDecl>();
    entity->id = entityID;
    entity->name = name;
    entity->types = typesVec;
    entity->trace = range;

    m_EntityDeclarations.push_back(std::move(entity));

    if (typesVec.size() > 0) {
      // Types are correct!
      for (declaration_id typeID : typesVec) {
        getGlobalScope()->getTypeDeclarations()->at(typeID).get()->entities.push_back(entityID);
      }
    }

    addDefinition(name, std::move(definitionData));

    TracePrint("Entity '{}' added to the scope: {}", name, m_Name);

  } else {
    CLI_ERROR("Type is not declared for '{}'", name);
  }
}
