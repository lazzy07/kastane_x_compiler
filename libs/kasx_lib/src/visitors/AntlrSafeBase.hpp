/*
* File name: AntlrSafeBase.hpp
* Project: KasX Compiler
* Author: Lasantha M Senanayake
* Date created: 2025-12-21 14:17:39
// Date modified: 2025-12-21 14:17:45
* ------
*/

#pragma once

// We want 'EOF' macro NOT defined while compiling ANTLR headers (so they can
// define Recognizer::EOF etc.), but restored afterwards for fmt/spdlog.

#include <cstdio>  // defines EOF

#if defined(EOF)
#pragma push_macro("EOF")
#undef EOF
#define __KASX_EOF_PUSHED 1
#endif

#include <KasXBaseVisitor.h>  // generated ANTLR header (pulls antlr4-common.h)

#ifdef __KASX_EOF_PUSHED
#pragma pop_macro("EOF")  // restore the macro exactly as it was
#undef __KASX_EOF_PUSHED
#else
// If EOF wasn’t defined at push time, ensure it exists now for fmt.
#include <stdio.h>
#endif
