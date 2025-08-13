log_status("Antlr lib building: STARTED")

set(ANTLR_VER "4.13.2")
set(ANTLR_TAG "v${ANTLR_VER}")

log_status("Downloading Antlr ${ANTLR_TAG}: STARTED")

set(ANTLR_DIR "${CMAKE_SOURCE_DIR}/vendor/antlr-${ANTLR_VER}")

if(NOT EXISTS "${ANTLR_DIR}/LICENSE.txt")
  file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/vendor")
  set(_zip "${CMAKE_BINARY_DIR}/antlr-${ANTLR_TAG}.zip")
  file(DOWNLOAD
    "https://github.com/antlr/antlr4/archive/refs/tags/${ANTLR_VER}.zip"
    "${_zip}" SHOW_PROGRESS TLS_VERIFY ON)
  execute_process(COMMAND ${CMAKE_COMMAND} -E tar xvf "${_zip}"
                  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}" RESULT_VARIABLE rc)
  if(NOT rc EQUAL 0)
    message(FATAL_ERROR "Failed to extract antlr ${ANTLR_TAG}")
  endif()
  file(RENAME "${CMAKE_BINARY_DIR}/antlr4-${ANTLR_VER}" "${ANTLR_DIR}")
endif()

set(BUILD_TESTING OFF CACHE BOOL "" FORCE)

list(FILTER ALL_CXX_FILES EXCLUDE REGEX ".*/vendor/antlr-4\\.13\\.2/.*")