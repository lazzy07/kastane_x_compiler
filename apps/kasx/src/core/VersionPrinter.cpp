/*
* File name: VersionPrinter.cpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-11-15 19:55:29
// Date modified: 2025-12-14 13:09:24
* ------
*/

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
