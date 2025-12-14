#include "GlobalScope.hpp"

#include <memory>
#include <string_view>
#include <vector>

#include "ActionScope.hpp"
#include "Log.hpp"
#include "Scope.hpp"
#include "kasx/KasXCompiler.hpp"

KasX::Compiler::Core::GlobalScope::GlobalScope() : Scope("Global", SCOPE_TYPES::GLOBAL) {
  CORE_TRACE("Scope: Global Initialized");
}

KasX::Compiler::Core::GlobalScope::~GlobalScope() { CORE_TRACE("Scope: Global Terminated"); }

void KasX::Compiler::Core::GlobalScope::initNewType(const std::string& name, const KasX::Compiler::Trace::Range& range,
                                                    const std::vector<std::string>& parents) {
  if (getScopeType() != SCOPE_TYPES::GLOBAL) {
    CORE_ERROR("Type declarations should be done only inside the global scope: {}", name);
    return;
  }

  TracePrint("New type initialization started: {}", name);

  if (getDefinition(name) != nullptr) {
    CLI_ERROR("Type '{}' already exists as a definition", name);
    return;
  }

  std::vector<KasX::declaration_id> parentIDs = getParentIDs(name, parents);

  // If the function continues here, all the parents are found, no errors.
  declaration_id typeID = this->m_TypeDeclarations.size();

  // Creating definition data for the type declaration
  auto definitionData = std::make_unique<DeclarationData>();
  definitionData->id = typeID;
  definitionData->type = KasX::Compiler::DataStructures::DECLARATION_TYPES::TYPE_DEFINITION;

  auto type = std::make_unique<KasX::Compiler::DataStructures::TypeDecl>();

  type->id = typeID;
  type->parents = parentIDs;
  type->trace = range;
  type->name = name;

  // If there are no parents defined, the parent should be 'entity'
  if (parentIDs.empty()) {
    // No parent id, set the parent to 'entity', but only if it is not 'entity'
    if (name != "entity") {
      DeclarationData* entityDefinition = getDefinition("entity");
      declaration_id entityID = entityDefinition->id;

      m_TypeDeclarations.at(entityID).get()->children.push_back(typeID);
      TracePrint("Type definition with no parents '{}' added to entity type as a child", name);
    }
  }

  // Adding the new child to the parent
  for (declaration_id parentID : parentIDs) {
    DataStructures::TypeDecl* parent = m_TypeDeclarations.at(parentID).get();
    parent->children.push_back(typeID);
  }

  // Adding the new type to the definitions
  addDefinition(type->name, std::move(definitionData));

  // Add the new type to the types of the scope
  TracePrint("New type {} added to the scope: {}.", type->name, this->getScopeName());
  m_TypeDeclarations.push_back(std::move(type));
}

void KasX::Compiler::Core::GlobalScope::initNewFluent(const std::string& name, const KasX::Compiler::Trace::Range& range,
                                                      const ParamList& params, const std::string& dataType) {
  TracePrint("Started initializing a new fluent '{}' with data type: '{}'", name, dataType);

  if (getScopeType() != SCOPE_TYPES::GLOBAL) {
    CORE_ERROR("Fluent declarations should be done only inside the global scope: {}", name);
    return;
  }

  DeclarationData* dataTypeDef = getDefinition(dataType);

  if (dataTypeDef == nullptr) {
    CLI_ERROR("Data type '{}' of the fluent '{}' does not exist", dataType, name);
    return;
  }

  if (dataTypeDef->type != DataStructures::DECLARATION_TYPES::TYPE_DEFINITION) {
    CLI_ERROR("Data type '{}' of the fluent '{}' exist, but not as a data type", dataType, name);
  }

  declaration_id fluentID = m_FluentDeclarations.size();

  auto definitionData = std::make_unique<DeclarationData>();
  definitionData->id = fluentID;
  definitionData->type = DataStructures::DECLARATION_TYPES::FLUENT_DEFINITION;

  auto fluent = std::make_unique<DataStructures::FluentDecl>();
  fluent->id = fluentID;
  fluent->trace = range;
  fluent->dataType = dataTypeDef->id;
  fluent->name = name;

  // Adding fluent parameters
  declaration_id index = 0;
  for (const Param& param : params) {
    auto paramData = std::make_unique<DataStructures::Helpers::Parameter>();

    paramData->name = param.first;

    paramData->id = index;

    if (!param.second.empty()) {
      auto* paramDataType = getDefinition(param.second);

      if (paramDataType != nullptr) {
        if (paramDataType->type == DataStructures::DECLARATION_TYPES::TYPE_DEFINITION) {
          paramData->dataType = DataStructures::DECLARATION_TYPES::TYPE_DEFINITION;
          paramData->index = paramDataType->id;
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
      auto* paramDataType = getDefinition(param.first);

      if (paramDataType != nullptr) {
        if (paramDataType->type == DataStructures::DECLARATION_TYPES::ENTITY_DEFINITION) {
          paramData->dataType = DataStructures::DECLARATION_TYPES::ENTITY_DEFINITION;
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
    TracePrint("Parameter '{}' added to the fluent '{}'", paramData->name, name);
    fluent->parameters.push_back(std::move(paramData));
    index++;
  }

  this->generateGroundedFluent(fluent.get());
  TracePrint("Fluent declaration '{}' added to the scope: {}", name, this->getScopeName());
  this->m_FluentDeclarations.push_back(std::move(fluent));
}

KasX::Compiler::Core::ActionScope* KasX::Compiler::Core::GlobalScope::createActionScope(std::string name) {
  TracePrint("Creating an action scope: {}", name);

  std::unique_ptr<ActionScope> newActionScope = std::make_unique<ActionScope>(name, this);

  auto* actionScopePtr = newActionScope.get();

  m_ActionScopes.push_back(std::move(newActionScope));

  return actionScopePtr;
}

void KasX::Compiler::Core::GlobalScope::generateGroundedFluent(KasX::Compiler::DataStructures::FluentDecl* fluentDecl) {
  // Get the name of the fluent first
  std::string_view name = fluentDecl->name;
  TracePrint("Gathering data to ground the fluent: {}", name);
  // A vector to keep all the parameter options
  std::vector<declaration_id> paramPointers;

  // Get all the parameters of the fluent and iterate over them,
  for (const auto& param : fluentDecl->parameters) {
    TracePrint("Parameter: {} is processing of the fluent: {}", param->name, name);
    // Paramenter can have different data types, a reference to a type or an entity, so need to handle them separately
    // First handle the entity type
    if (param->dataType == DataStructures::DECLARATION_TYPES::ENTITY_DEFINITION) {
      TracePrint("Parameter: {} is an entity", param->name);
      auto pram = generateFluentParamEntity(&param);
    }

    if (param->dataType == DataStructures::DECLARATION_TYPES::TYPE_DEFINITION) {
      TracePrint("Paramter: {} is a type", param->name);
      generateFluentParamType(&param);
    }
  }
}

std::vector<KasX::declaration_id> KasX::Compiler::Core::GlobalScope::generateFluentParamEntity(
    std::unique_ptr<KasX::Compiler::DataStructures::Helpers::Parameter> const* parameter) {
  TracePrint("Handing entity paramter: {}", parameter->get()->name);
  std::vector<declaration_id> ptrs;
  ptrs.push_back(parameter->get()->id);
  return ptrs;
}

std::vector<KasX::declaration_id> KasX::Compiler::Core::GlobalScope::generateFluentParamType(
    std::unique_ptr<KasX::Compiler::DataStructures::Helpers::Parameter> const* parameter) {
  TracePrint("Handling type parameter: {}", parameter->get()->name);

  std::vector<declaration_id> ptrs;

  const auto typeID = parameter->get()->id;

  auto* typeDeclaration = this->m_TypeDeclarations.at(typeID).get();
  this->getEntitesFromType(typeDeclaration, &ptrs);
  TracePrint("{} entities found for paramter: {}", ptrs.size(), parameter->get()->name);

  if (ptrs.size() == 0) {
    CLI_ERROR("No entities found for paramter: {}", parameter->get()->name);
  }

  return ptrs;
}

void KasX::Compiler::Core::GlobalScope::getEntitesFromType(KasX::Compiler::DataStructures::TypeDecl* typeDecl,
                                                           std::vector<KasX::declaration_id>* declrationIDs) {
  const auto entities = typeDecl->entities;

  for (auto entity : entities) {
    declrationIDs->push_back(entity);
  }

  // Get the children of the type declaration and recursively find all the entities
  for (auto childTypeDeclID : typeDecl->children) {
    auto* childTypeDecl = this->m_TypeDeclarations.at(childTypeDeclID).get();
    getEntitesFromType(childTypeDecl, declrationIDs);
  }
}

void KasX::Compiler::Core::GlobalScope::handleCustomCharacterDefinition() {}
