log_status("Antlr Configuration: STARTED")
# Setting file paths
set(ANTLR_ROOT ${CMAKE_SOURCE_DIR}/vendor/antlr-4.13.2)

# Adding antlr subdirectories
set(ANTLR4_RUNTIME antlr4_static)
set(ANTLR_BUILD_CPP_TESTS OFF CACHE BOOL "" FORCE)
set(WITH_DEMO OFF CACHE BOOL "" FORCE)

add_subdirectory(${ANTLR_ROOT}/runtime/Cpp runtime/antlr4)

# Check for java
find_package(Java REQUIRED)
log_status("Java requirement: PASSED")

# Setting grammar file path and generated paths
set(ANTLR_GRAMMAR_FILE ${CMAKE_CURRENT_SOURCE_DIR}/grammar/KasX.g4)
set(ANTLR_GENERATED_DIR ${CMAKE_BINARY_DIR}/generated/antlr)

file(MAKE_DIRECTORY ${ANTLR_GENERATED_DIR})
log_status("Antlr generated folder created: ${ANTLR_GENERATED_DIR}")




log_status("Antlr JAR: ${ANTLR_JAR}")
log_status("Antlr grammar file: ${ANTLR_GRAMMAR_FILE}")
log_status("Antlr4 generator: STARTED")

add_custom_command(
  OUTPUT
  ${ANTLR_GENERATED_DIR}/KasXLexer.cpp
  ${ANTLR_GENERATED_DIR}/KasXParser.cpp
  ${ANTLR_GENERATED_DIR}/KasXBaseVisitor.cpp
  ${ANTLR_GENERATED_DIR}/KasXVisitor.cpp
  COMMAND ${Java_JAVA_EXECUTABLE}
    -jar ${ANTLR_JAR}
    -Dlanguage=Cpp
    -visitor
    -o ${ANTLR_GENERATED_DIR}
    ${ANTLR_GRAMMAR_FILE}
  DEPENDS ${ANTLR_GRAMMAR_FILE}
  COMMENT "Generating ANTLR4 parser/visitor from ${ANTLR_GRAMMAR_FILE}"
)

log_status("Antlr4 generator: FINISHED")

add_custom_target(
  kasx_parser DEPENDS
  ${ANTLR_GENERATED_DIR}/KasXLexer.cpp
  ${ANTLR_GENERATED_DIR}/KasXParser.cpp
  ${ANTLR_GENERATED_DIR}/KasXBaseVisitor.cpp
  ${ANTLR_GENERATED_DIR}/KasXVisitor.cpp
)

# Disable tidy on generated files wholesale
file(GLOB ANTLR_GEN_SOURCES "${ANTLR_GENERATED_DIR}/*.[ch]pp" "${ANTLR_GENERATED_DIR}/*.[ch]")
set_source_files_properties(${ANTLR_GEN_SOURCES} PROPERTIES CXX_CLANG_TIDY "")

# Disable on ANTLR runtime targets (added via add_subdirectory)
set_target_properties(antlr4_shared PROPERTIES CXX_CLANG_TIDY "")
set_target_properties(antlr4_static PROPERTIES CXX_CLANG_TIDY "")
# antlr4_tests may not exist in Release-only configs; guard it:
if(TARGET antlr4_tests)
  set_target_properties(antlr4_tests PROPERTIES CXX_CLANG_TIDY "")
endif()

log_status("Antlr Configuration: FINISHED")
