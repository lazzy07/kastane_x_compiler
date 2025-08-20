#pragma once
#include <kasx/Types.hpp>
#include <memory>
#include <vector>

#include "../data_structures/Definition.hpp"
#include "../data_structures/DefinitionTypes.hpp"
#include "../data_structures/Type.hpp"
#include "../visitors/ProgramVisitor.hpp"

namespace KasX::Compiler::Core {
struct DefinitionData {
  KasX::Compiler::DataStructures::DEFINITION_TYPES type;
  definition_id id;
};

class Domain {
 public:
  explicit Domain(DomainData &data);
  ~Domain();

  void InitVisitor();
  void InitDefaultTypes();
  void InitNewType(const std::string &name, const FileTrace &trace,
                   const std::vector<std::string> &parents = {});

  DefinitionData *GetDefinition(const std::string &name);

 private:
  // Meta-Data that the domain initialized with
  DomainData m_DomainData;
  // Program visitor for the domain
  std::unique_ptr<KasX::Compiler::Visitor::ProgramVisitor> m_ProgramVisitor;

  // Definition holders
  std::unordered_map<std::string, std::unique_ptr<DefinitionData>> m_Definitions;
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::Type>> m_Types;
};
}  // namespace KasX::Compiler::Core