#include "Scope.hpp"

#include <Log.hpp>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "kasx/Types.hpp"

KasX::Compiler::Core::Scope::Scope(std::string name, SCOPE_TYPES type, std::unique_ptr<Scope> parent)
    : m_Name(std::move(name)), m_Type(type), m_Parent(std::move(parent)) {
  CORE_TRACE("Scope initialized {}", m_Name);
}

KasX::Compiler::Core::Scope::~Scope() { CORE_TRACE("Scope Destroyed {}", m_Name); }

KasX::Compiler::Core::DefinitionData* KasX::Compiler::Core::Scope::GetDefinition(const std::string& name) {
  CLI_TRACE("Checking if definition already exists: {}", name);

  auto dataPtr = m_Definitions.find(name);
  if (dataPtr == m_Definitions.end()) {
    CLI_TRACE("Definition {} - does not exist", name);
    return nullptr;
  }

  CLI_TRACE("Definition: {} - already exists", name);
  return dataPtr->second.get();
}

void KasX::Compiler::Core::Scope::AddDefinition(const std::string& name, std::unique_ptr<DefinitionData> data) {
  // username - lazzy07 TODO: Handle the error
  if (m_Type != SCOPE_TYPES::GLOBAL) {
    CLI_ERROR("Declarations must be inside the global scope");
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

std::vector<KasX::definition_id> KasX::Compiler::Core::Scope::GetParentIDs(const std::string& name,
                                                                           const std::vector<std::string>& parents) {
  std::vector<definition_id> parentIDs;

  for (std::string parent : parents) {
    // username - lazzy07 TODO: Handle the error

    DefinitionData* parentDef = GetDefinition(parent);

    if (parentDef == nullptr) {
      CORE_ERROR("For the type: {} parent {}, does not exist", name, parent);
      return {};
    }

    if (parentDef->type != DataStructures::DEFINITION_TYPES::TYPE_DEFINITION) {
      CLI_ERROR("Parent/Type '{}' for '{}' does not exist as a type", parent, name);
      return {};
    }

    parentIDs.push_back(parentDef->id);
  }

  return parentIDs;
}

void KasX::Compiler::Core::Scope::InitNewType(const std::string& name, const KasX::Compiler::Trace::Range& range,
                                              const std::vector<std::string>& parents) {
  if (m_Type != SCOPE_TYPES::GLOBAL) {
    CORE_ERROR("Type declarations should be done only inside the global scope: {}", name);
    return;
  }

  CORE_TRACE("New type initialization started: {}", name);

  if (GetDefinition(name) != nullptr) {
    CLI_ERROR("Type '{}' already exists as a definition", name);
    return;
  }

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

  // If there are no parents defined, the parent should be 'entity'
  if (parentIDs.empty()) {
    // No parent id, set the parent to 'entity', but only if it is not 'entity'
    if (name != "entity") {
      DefinitionData* entityDefinition = m_Definitions.find("entity")->second.get();
      definition_id entityID = entityDefinition->id;

      m_Types.at(entityID).get()->children.push_back(typeID);
      CLI_TRACE("Type definition with no parents '{}' added to entity type as a child", name);
    }
  }

  // Adding the new child to the parent
  for (definition_id parentID : parentIDs) {
    DataStructures::Type* parent = m_Types.at(parentID).get();
    parent->children.push_back(typeID);
  }

  // Adding the new type to the definitions
  AddDefinition(type->name, std::move(definitionData));

  // Add the new type to the types of the scope
  CLI_INFO("New type {} added to the scope: {}.", type->name, this->m_Name);
  m_Types.push_back(std::move(type));
}

void KasX::Compiler::Core::Scope::InitNewEntity(const std::string& name, const KasX::Compiler::Trace::Range& range,
                                                const std::vector<std::string>& types) {
  CORE_TRACE("New entity initialization started: {}", name);

  if (m_Type != SCOPE_TYPES::GLOBAL) {
    CORE_ERROR("Entity declarations should be done only inside the global scope: {}", name);
    return;
  }

  // First check if the entity already exists or not
  if (GetDefinition(name) != nullptr) {
    CLI_ERROR("Entity '{}' already exists as a definition", name);
    return;
  }

  definition_id entityID = m_Entities.size();

  if (types.size() > 0) {
    // Typename declaration is correct (size wise), has exactly one type
    auto typesVec = GetParentIDs(name, types);

    auto definitionData = std::make_unique<DefinitionData>();
    definitionData->id = entityID;
    definitionData->type = DataStructures::ENTITY_DEFINITION;

    auto entity = std::make_unique<DataStructures::Entity>();
    entity->id = entityID;
    entity->name = name;
    entity->types = typesVec;
    entity->trace = range;

    m_Entities.push_back(std::move(entity));

    if (typesVec.size() > 0) {
      // Types are correct!
      for (definition_id typeID : typesVec) {
        m_Types.at(typeID).get()->entities.push_back(entityID);
      }
    }

    AddDefinition(name, std::move(definitionData));

    CLI_INFO("Entity '{}' added to the scope: {}", name, m_Name);

  } else {
    CLI_ERROR("Type is not declared for '{}'", name);
  }
}

void KasX::Compiler::Core::Scope::InitNewFluent(const std::string& name, const KasX::Compiler::Trace::Range& range,
                                                const ParamList& params, const std::string& dataType) {
  CLI_TRACE("Started initializing a new fluent '{}' with data type: '{}'", name, dataType);

  if (m_Type != SCOPE_TYPES::GLOBAL) {
    CORE_ERROR("Fluent declarations should be done only inside the global scope: {}", name);
    return;
  }

  DefinitionData* dataTypeDef = GetDefinition(dataType);

  if (dataTypeDef == nullptr) {
    CLI_ERROR("Data type '{}' of the fluent '{}' does not exist", dataType, name);
    return;
  }

  if (dataTypeDef->type != DataStructures::DEFINITION_TYPES::TYPE_DEFINITION) {
    CLI_ERROR("Data type '{}' of the fluent '{}' exist, but not as a data type", dataType, name);
  }

  definition_id fluentID = m_Fluents.size();

  auto definitionData = std::make_unique<DefinitionData>();
  definitionData->id = fluentID;
  definitionData->type = DataStructures::FLUENT_DEFINITION;

  auto fluent = std::make_unique<DataStructures::Fluent>();
  fluent->id = fluentID;
  fluent->trace = range;
  fluent->dataType = dataTypeDef->id;

  std::string finalName = std::to_string(fluentID) + "(";

  // Adding fluent parameters
  definition_id index = 0;
  for (const Param& param : params) {
    auto paramData = std::make_unique<DataStructures::Helpers::Parameter>();

    paramData->name = param.first;

    if (index != 0) {
      finalName += ",";
    }

    paramData->id = index;

    if (!param.second.empty()) {
      finalName += ":";
      auto* paramDataType = GetDefinition(param.second);

      if (paramDataType != nullptr) {
        if (paramDataType->type == DataStructures::DEFINITION_TYPES::TYPE_DEFINITION) {
          paramData->dataType = DataStructures::DEFINITION_TYPES::TYPE_DEFINITION;
          paramData->index = paramDataType->id;
          finalName += std::to_string(paramDataType->id);
        } else {
          CLI_ERROR("Parameter '{}' of the fluent '{}' definition found: '{}' but it is not a type", param.first, name,
                    param.second);
          return;
        }
      } else {
        CLI_ERROR("Parameter '{}' of the fluent '{}' datatype cannot be found: '{}'", param.first, name, param.second);
        return;
      }
    } else {
      auto* paramDataType = GetDefinition(param.first);

      if (paramDataType != nullptr) {
        if (paramDataType->type == DataStructures::DEFINITION_TYPES::ENTITY_DEFINITION) {
          paramData->dataType = DataStructures::DEFINITION_TYPES::ENTITY_DEFINITION;
          paramData->index = paramDataType->id;
        } else {
          CLI_ERROR("Parameter '{}' of the fluent '{}' definition found: '{}' but it is not an entity", param.first, name,
                    param.second);
          return;
        }
      } else {
        CLI_ERROR("Parameter (Entity) '{}' of the fluent '{}' cannot be found", param.first, name, param.second);
        return;
      }
    }
    CLI_TRACE("Parameter '{}' added to the fluent '{}'", paramData->name, name);
    fluent->parameters.push_back(std::move(paramData));
    index++;
  }

  finalName += "):" + std::to_string(fluent->dataType);

  // First check if the fluent already exists or not
  if (GetDefinition(finalName) != nullptr) {
    CLI_ERROR("Entity '{}' already exists as a definition", finalName);
    return;
  }

  // Setting the fluent name.
  fluent->name = finalName;

  AddDefinition(finalName, std::move(definitionData));

  m_Fluents.push_back(std::move(fluent));

  CLI_INFO("Fluent declaration added: '{}' to the scope: {}", finalName, this->m_Name);
}
