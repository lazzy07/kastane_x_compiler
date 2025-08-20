#pragma once

// We want 'EOF' macro NOT defined while compiling ANTLR headers (so they can
// define Recognizer::EOF etc.), but restored afterwards for fmt/spdlog.

#include <cstdio>  // defines EOF

#if defined(EOF)
#pragma push_macro("EOF")
#undef EOF
#define __KASX_EOF_PUSHED 1
#endif

#include <KasXLexer.h>
#include <KasXParser.h>
#include <antlr4-runtime.h>

#ifdef __KASX_EOF_PUSHED
#pragma pop_macro("EOF")  // restore the macro exactly as it was
#undef __KASX_EOF_PUSHED
#else
// If EOF wasn’t defined at push time, ensure it exists now for fmt.
#include <stdio.h>
#endif