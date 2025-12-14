#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "../data_structures/declarations/DeclarationTypes.hpp"
#include "../data_structures/declarations/EntityDecl.hpp"
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

class GlobalScope;

class Scope : public TraceableClass {
 public:
  Scope(std::string name, SCOPE_TYPES type);
  ~Scope() override;

  // Getters
  SCOPE_TYPES getScopeType() { return m_Type; };
  std::string_view getScopeName() { return m_Name; };
  std::unordered_map<std::string, std::unique_ptr<DeclarationData>>* getDefinitions() { return &m_Definitions; };

  DeclarationData* getDefinition(const std::string& name);  // Get definition by name
  void addDefinition(const std::string& name, std::unique_ptr<DeclarationData> data);

  void initNewEntity(const std::string& name, const KasX::Compiler::Trace::Range& range,
                     const std::vector<std::string>& type = {});

  std::vector<KasX::declaration_id> getParentIDs(const std::string& name, const std::vector<std::string>& parents);
  virtual GlobalScope* getGlobalScope() = 0;

 private:
  std::string m_Name;
  SCOPE_TYPES m_Type;

  // Definition holders
  std::unordered_map<std::string, std::unique_ptr<DeclarationData>>
      m_Definitions;  // All the definitions can be found here except for fluent declarations
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::EntityDecl>> m_EntityDeclarations;  // Entities definitions
};
}  // namespace KasX::Compiler::Core
