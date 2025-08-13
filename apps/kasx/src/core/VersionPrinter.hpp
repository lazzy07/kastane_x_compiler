#pragma once
#include <string>

namespace KasX::App::Core {
class VersionPrinter {
 public:
  static void printVersionDetails();

 private:
  static std::string getLogo();
};
}  // namespace KasX::App::Core