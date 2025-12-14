#pragma once

#include "Scope.hpp"

namespace KasX::Compiler::Core {
class ActionScope : public Scope {
 public:
  explicit ActionScope(std::string name, GlobalScope* parent);
  GlobalScope* getGlobalScope() override;

 private:
  GlobalScope* m_GlobalScope;
};
}  // namespace KasX::Compiler::Core
