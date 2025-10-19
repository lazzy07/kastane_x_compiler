#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "../data_structures/DefinitionTypes.hpp"
#include "../data_structures/Entity.hpp"
#include "../data_structures/Fluent.hpp"
#include "../data_structures/InitialFluent.hpp"
#include "../data_structures/Type.hpp"
#include "../data_structures/helpers/Parameter.hpp"
#include "../trace/Range.hpp"
#include "kasx/Types.hpp"

using Param = std::pair<std::string, std::string>;
using ParamList = std::vector<Param>;

namespace KasX::Compiler::Core {
struct DefinitionData {
  KasX::Compiler::DataStructures::DEFINITION_TYPES type;
  definition_id id;
};

enum SCOPE_TYPES { GLOBAL, BLOCK, ACTION, TRIGGER, UTILITY, PARAM_LIST };

class Scope {
 public:
  Scope(std::string name, SCOPE_TYPES type, std::unique_ptr<Scope> parent = nullptr);
  ~Scope();

  DefinitionData *GetDefinition(const std::string &name);  // Get definition by name

  void InitNewType(const std::string &name, const KasX::Compiler::Trace::Range &range,
                   const std::vector<std::string> &parents = {});
  void InitNewEntity(const std::string &name, const KasX::Compiler::Trace::Range &range,
                     const std::vector<std::string> &type = {});

  void InitNewFluent(const std::string &name, const KasX::Compiler::Trace::Range &range,
                     const ParamList &params, const std::string &dataType);

  inline SCOPE_TYPES GetScopeType() { return m_Type; };

  void InitInitialFulent(const std::string &name, const KasX::Compiler::Trace::Range &range);

 private:
  std::string m_Name;
  SCOPE_TYPES m_Type;
  std::unique_ptr<Scope> m_Parent;
  std::vector<std::unique_ptr<Scope>> m_Children;

  // Definition holders
  std::unordered_map<std::string, std::unique_ptr<DefinitionData>>
      m_Definitions;  // All the definitions can be found here
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::Type>> m_Types;  // Types definitions
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::Entity>>
      m_Entities;  // Entities definitions
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::Fluent>>
      m_Fluents;  // Fluent definitions
  std::vector<std::unique_ptr<DataStructures::Helpers::Parameter>> m_Parameters;
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::InitialFluent>>
      m_InitialFluents;  // Initial fluent values are stored in here.

  void AddDefinition(const std::string &name, std::unique_ptr<DefinitionData> data);
  std::vector<KasX::definition_id> GetParentIDs(const std::string &name,
                                                const std::vector<std::string> &parents);
};
}  // namespace KasX::Compiler::Core