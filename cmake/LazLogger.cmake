set(LAZLOGGER_VER "1.0.0")
set(LAZLOGGER_TAG "v${LAZLOGGER_VER}")
set(LAZLOGGER_DIR "${CMAKE_SOURCE_DIR}/vendor/laz_logger-${LAZLOGGER_VER}")

if(NOT EXISTS "${LAZLOGGER_DIR}/CMakeLists.txt")
  file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/vendor")
  set(_zip "${CMAKE_BINARY_DIR}/laz_logger-${LAZLOGGER_TAG}.zip")
  file(DOWNLOAD
    "https://github.com/lazzy07/laz_logger/archive/refs/tags/${LAZLOGGER_TAG}.zip"
    "${_zip}" SHOW_PROGRESS TLS_VERIFY ON)
  execute_process(COMMAND ${CMAKE_COMMAND} -E tar xvf "${_zip}"
                  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}" RESULT_VARIABLE rc)
  if(NOT rc EQUAL 0)
    message(FATAL_ERROR "Failed to extract laz_logger ${LAZLOGGER_TAG}")
  endif()
  file(RENAME "${CMAKE_BINARY_DIR}/laz_logger-${LAZLOGGER_VER}" "${LAZLOGGER_DIR}")
endif()

set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
add_subdirectory("${LAZLOGGER_DIR}" EXCLUDE_FROM_ALL)

list(FILTER ALL_CXX_FILES EXCLUDE REGEX ".*/vendor/laz_logger-1\\.0\\.0/.*")