#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "../data_structures/declarations/DeclarationTypes.hpp"
#include "../data_structures/declarations/EntityDecl.hpp"
#include "../data_structures/declarations/FluentDecl.hpp"
#include "../data_structures/declarations/TypeDecl.hpp"
#include "../data_structures/expressions/Expression.hpp"
#include "../data_structures/helpers/Parameter.hpp"
#include "../trace/Range.hpp"
#include "TraceableClass.hpp"
#include "kasx/Types.hpp"

using Param = std::pair<std::string, std::string>;
using ParamList = std::vector<Param>;

namespace KasX::Compiler::Core {
struct DeclarationData {
  KasX::Compiler::DataStructures::DECLARATION_TYPES type;
  declaration_id id;
};

enum SCOPE_TYPES : std::uint8_t { GLOBAL, BLOCK, ACTION, TRIGGER, UTILITY, PARAM_LIST };

class Scope : TraceableClass {
 public:
  Scope(std::string name, SCOPE_TYPES type, std::unique_ptr<Scope> parent = nullptr);
  ~Scope() override;

  DeclarationData* GetDefinition(const std::string& name);  // Get definition by name

  void AddDefinition(const std::string& name, std::unique_ptr<DeclarationData> data);

  void InitNewType(const std::string& name, const KasX::Compiler::Trace::Range& range,
                   const std::vector<std::string>& parents = {});
  void InitNewEntity(const std::string& name, const KasX::Compiler::Trace::Range& range,
                     const std::vector<std::string>& type = {});

  void InitNewFluent(const std::string& name, const KasX::Compiler::Trace::Range& range, const ParamList& params,
                     const std::string& dataType);

  SCOPE_TYPES GetScopeType() { return m_Type; };

  void AddExpressionToInitialState(const KasX::Compiler::DataStructures::Expression* expression);

 private:
  std::string m_Name;
  SCOPE_TYPES m_Type;
  std::unique_ptr<Scope> m_Parent;
  std::vector<std::unique_ptr<Scope>> m_Children;

  // Definition holders
  std::unordered_map<std::string, std::unique_ptr<DeclarationData>> m_Definitions;  // All the definitions can be found here
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::TypeDecl>> m_TypeDeclarations;      // Types definitions
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::EntityDecl>> m_EntityDeclarations;  // Entities definitions
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::FluentDecl>> m_FluentDeclarations;  // Fluent definitions
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::Helpers::Parameter>> m_Parameters;
  std::vector<KasX::Compiler::DataStructures::Expression> m_InitialState;  // Initial state of the domain

  void AddDeclaration(const std::string& name, std::unique_ptr<DeclarationData> data);
  std::vector<KasX::declaration_id> GetParentIDs(const std::string& name, const std::vector<std::string>& parents);
};
}  // namespace KasX::Compiler::Core
