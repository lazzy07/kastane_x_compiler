cmake_minimum_required(VERSION 3.15)

set(LOGGER_PREPEND "[KasX EXE] ")

log_status("Building the executable: STARTED")

project(
  kastane_x_executable 
  VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
  LANGUAGES CXX
)

file(
  GLOB_RECURSE 
  EXE_SRC_FILES 
  CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/**/*.cpp"
)

log_status("Grabbed source files: ${EXE_SRC_FILES}")

add_executable(
  kasx 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp
  ${EXE_SRC_FILES}
)

target_link_libraries(kasx PRIVATE lazlogger)

target_include_directories(
  kasx
  PRIVATE "${CMAKE_BINARY_DIR}/generated"
)

target_compile_definitions(kasx PRIVATE
  CORE_LOGGER_NAME="KASX_APP"
  CLI_LOGGER_NAME="KASX_CLI"
)

log_status("Executable configuration: FINISHED")

log_status("Building the executable: FINISHED")