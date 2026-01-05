cmake_minimum_required(VERSION 3.15)

project(KasXCompiler LANGUAGES CXX)

set(LOGGER_PREPEND "[KasX COMPILER] ")

# ################## General project configs ###########################
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ################## Generate the library ###########################
file(
  GLOB_RECURSE 
  COMPILER_SRC_FILES 
  CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

include(Antlr)

add_library(
  kasx_compiler SHARED
  ${COMPILER_SRC_FILES}
  ${ANTLR_GENERATED_DIR}/KasXLexer.cpp
  ${ANTLR_GENERATED_DIR}/KasXParser.cpp
  ${ANTLR_GENERATED_DIR}/KasXBaseVisitor.cpp
  ${ANTLR_GENERATED_DIR}/KasXVisitor.cpp
)

target_compile_definitions(kasx_compiler PRIVATE
  CORE_LOGGER_NAME="KASX_LIB"
  CLI_LOGGER_NAME="KASX_CLI_LIB"
)

# Adding kasx_parser custom target created by Antlr.cmake
add_dependencies(kasx_compiler kasx_parser)
target_link_libraries(kasx_compiler PRIVATE antlr4_shared PRIVATE lazlogger)

target_include_directories(
  kasx_compiler
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE ${ANTLR_GENERATED_DIR}
  
  PRIVATE ${ANTLR_ROOT}/project/runtime/Cpp/runtime/src
)
