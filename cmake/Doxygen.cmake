log_status("Doxygen generation: STARTED")

find_package(Doxygen REQUIRED)

################ Doxygen awesome css configuration ################

include(FetchContent)

FetchContent_Declare(
  doxygen-awesome-css
  GIT_REPOSITORY https://github.com/jothepro/doxygen-awesome-css.git
  GIT_TAG v2.4.1
)

FetchContent_MakeAvailable(doxygen-awesome-css)

FetchContent_GetProperties(doxygen-awesome-css SOURCE_DIR AWESOME_CSS_DIR)

###################################################################

# Doxygenfile template with cmake variables (Like: DOXY_PROJECT_NUMBER)
set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/Doxyfile.in)
set(DOXYGEN_OUT ${CMAKE_BINARY_DIR}/Doxyfile)

# Setting the project version in doxygen.
set(DOXY_PROJECT_NUMBER "${GIT_VERSION} (${GIT_COMMIT_HASH}, ${GIT_COMMIT_DATE})")

log_status("Doxygen project number: ${DOXY_PROJECT_NUMBER}")

configure_file(
  ${DOXYGEN_IN}
  ${DOXYGEN_OUT}
  @ONLY
)

add_custom_target(
  docs
  COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Generating API documentation with Doxygen"
)

log_status("Doxygen generation: FINISHED")
