#include "Domain.hpp"

#include <Log.hpp>

#include "../visitors/AntlrSafeRuntime.hpp"

KasX::Compiler::Core::Domain::Domain(DomainData &data) {
  CORE_TRACE("Domain Initialized");

  m_DomainData = std::move(data);
  m_ProgramVisitor = std::make_unique<Visitor::ProgramVisitor>(this);
}

KasX::Compiler::Core::Domain::~Domain() { CORE_TRACE("Domain Terminated"); }

void KasX::Compiler::Core::Domain::InitVisitor() {
  CORE_TRACE("Visitor Started");

  antlr4::ANTLRInputStream input(m_DomainData.fileStream);
  KasXLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  KasXParser parser(&tokens);

  antlr4::tree::ParseTree *tree = parser.prog();

  CLI_INFO("Parse tree completed: {}", m_DomainData.domainName);

  CLI_INFO("Visiting parse tree of {}", m_DomainData.domainName);
  this->InitDefaultTypes();
  m_ProgramVisitor->visit(tree);
}

void KasX::Compiler::Core::Domain::InitDefaultTypes() {
  CLI_TRACE("Initial types added: number, boolean, entity");
  this->InitNewType("number", {});
  this->InitNewType("boolean", {});
  this->InitNewType("entity", {});
}

void KasX::Compiler::Core::Domain::InitNewType(const std::string &name, const FileTrace &trace,
                                               const std::vector<std::string> &parents) {
  auto currentDef = this->GetDefinition(name);

  if (currentDef != nullptr) {
    CLI_ERROR("Cannot create the definition {} since it already exists.", name);
    return;
  }

  CLI_TRACE("Creating new type definition: {}", name);

  std::vector<definition_id> parentRefs;

  for (const auto &parent : parents) {
    auto *parentRef = this->GetDefinition(parent);
    if (parentRef != nullptr) {
      if (parentRef->type == KasX::Compiler::DataStructures::DEFINITION_TYPES::TYPE_DEFINITION) {
        CLI_TRACE("Parent found for: {} - Parent type: {}", name, parent);

        parentRefs.push_back(parentRef->id);
      } else {
        // TODO: Handle the error properly
        CLI_ERROR("Reference with the name {} already exists which is not a type");
      }

    } else {
      // TODO: Handle the error properly!
      CLI_ERROR("Could not find parent type for : {} of parent type {}", name, parent);
      return;
    }
  }

  auto typeDef = std::make_unique<KasX::Compiler::DataStructures::Type>();
  typeDef->id = m_Types.size();
  typeDef->name = name;
  typeDef->trace = trace;
  typeDef->parents = parentRefs;

  std::unique_ptr<DefinitionData> data = std::make_unique<DefinitionData>();
  // Setting the definition type to "type"
  data->type = KasX::Compiler::DataStructures::DEFINITION_TYPES::TYPE_DEFINITION;
  data->id = typeDef->id;

  for (auto parentRef : parentRefs) {
    auto parentType = m_Types.at(parentRef).get();
    if (parentType != nullptr) {
      parentType->children.push_back(typeDef->id);
      CLI_TRACE("Type Child: {} added to the Parent: {}", typeDef->name, parentType->name);
    }
  }

  m_Definitions.emplace(typeDef->name, std::move(data));
  m_Types.push_back(std::move(typeDef));
  CLI_INFO("Type-Definition added {}", name);
}

KasX::Compiler::Core::DefinitionData *KasX::Compiler::Core::Domain::GetDefinition(
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
