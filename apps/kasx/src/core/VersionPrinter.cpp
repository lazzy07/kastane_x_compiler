#include "VersionPrinter.hpp"

#include <Log.hpp>
#include <kasx/Version.hpp>

void KasX::App::Core::VersionPrinter::printVersionDetails() {
  CLI_INFO("\n\n" + VersionPrinter::getLogo());
  CLI_INFO("---------------------------------------------------");
  CLI_TRACE("KastaneX Compiler: {}", PROJECT_VERSION);
  CLI_TRACE("KastaneX Build Date: {}", PROJECT_COMMIT_DATE);
  CLI_TRACE("Created by @lazzy07 (https://github.com/lazzy07)");
  CLI_INFO("---------------------------------------------------\n\n");
}

std::string KasX::App::Core::VersionPrinter::getLogo() {
  return R"(
██╗  ██╗ █████╗ ███████╗████████╗ █████╗ ███╗   ██╗███████╗   ██╗  ██╗
██║ ██╔╝██╔══██╗██╔════╝╚══██╔══╝██╔══██╗████╗  ██║██╔════╝   ╚██╗██╔╝
█████╔╝ ███████║███████╗   ██║   ███████║██╔██╗ ██║█████╗█████╗╚███╔╝ 
██╔═██╗ ██╔══██║╚════██║   ██║   ██╔══██║██║╚██╗██║██╔══╝╚════╝██╔██╗ 
██║  ██╗██║  ██║███████║   ██║   ██║  ██║██║ ╚████║███████╗   ██╔╝ ██╗
╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝   ╚═╝  ╚═╝
                                                                      
        )";
}
