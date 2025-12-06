#pragma once

#include <memory>
#include <vector>

#include "../data_structures/declarations/FluentDecl.hpp"
#include "../data_structures/declarations/TypeDecl.hpp"
#include "../data_structures/expressions/Expression.hpp"
#include "Scope.hpp"

namespace KasX::Compiler::Core {
class GlobalScope : public Scope {
 public:
  GlobalScope();
  ~GlobalScope() override;

  /**
   * @brief Add a new expression to the initial state, initial state is stored only in the Global Scope
   *
   * @param expression - Expression that is added to the initial state.
   */
  void addExpressionToInitialState(const KasX::Compiler::DataStructures::Expression* expression);
  void initNewFluent(const std::string& name, const KasX::Compiler::Trace::Range& range, const ParamList& params,
                     const std::string& dataType);
  void initNewType(const std::string& name, const KasX::Compiler::Trace::Range& range,
                   const std::vector<std::string>& parents = {});

  /**
   * @brief Returns fluent declarations
   *
   * Fluent declarations are different from other declarations. Type and Entity declarations are in #m_EntityDeclarations and
   * #m_TypeDeclarations
   *
   * @param name Name of the fluent declaration that needs to be retrieved
   *
   * @warning Since 2 fluents can have same declaration name, fluent declarations are seperated from other declarations
   * @example go_to(character: Character) go_to(item: Item)
   */
  DataStructures::FluentDecl* getFluentDeclarations(const std::string& name);
  std::vector<std::unique_ptr<DataStructures::TypeDecl>>* getTypeDeclarations() { return &m_TypeDeclarations; };
  GlobalScope* getGlobalScope() override { return this; }

 private:
  std::vector<std::unique_ptr<Scope>> m_Children;  ///< Children of this scope
  Scope* m_Parent;  ///< Parents of this scope, currently the global scope with current design of Sabre language
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::TypeDecl>>
      m_TypeDeclarations;  ///< Types definitions (Types can be defined only inside the GlobalScope)
  std::vector<std::unique_ptr<KasX::Compiler::DataStructures::FluentDecl>>
      m_FluentDeclarations;  ///< Fluent definitions (Fluents can be declared only inside the GlobalScope)
  std::vector<KasX::Compiler::DataStructures::Expression> m_InitialState;  ///< Initial state of the domain
};
}  // namespace KasX::Compiler::Core
