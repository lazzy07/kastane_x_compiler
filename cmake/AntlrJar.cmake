set(ANTLR_VERSION "4.13.2")
set(ANTLR_JAR_NAME "antlr-${ANTLR_VERSION}-complete.jar")

set(ANTLR_URL "https://www.antlr.org/download/${ANTLR_JAR_NAME}")

set(ANTLR_OUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/antlr-jar")
set(ANTLR_JAR      "${ANTLR_OUT_DIR}/${ANTLR_JAR_NAME}")

# To find it once locally:  sha256sum antlr-4.13.1-complete.jar
set(ANTLR_JAR_SHA256 "")

# --- Download on first configure ---
if(NOT EXISTS "${ANTLR_JAR}")
  file(MAKE_DIRECTORY "${ANTLR_OUT_DIR}")
  message(STATUS "Downloading ${ANTLR_JAR_NAME} from ${ANTLR_URL}")

  if(ANTLR_JAR_SHA256)
    file(DOWNLOAD
      "${ANTLR_URL}" "${ANTLR_JAR}"
      EXPECTED_HASH "SHA256=${ANTLR_JAR_SHA256}"
      SHOW_PROGRESS
      TLS_VERIFY ON
      STATUS _dl
    )
  else()
    file(DOWNLOAD
      "${ANTLR_URL}" "${ANTLR_JAR}"
      SHOW_PROGRESS
      TLS_VERIFY ON
      STATUS _dl
    )
  endif()

  list(GET _dl 0 _code)
  if(NOT _code EQUAL 0)
    message(FATAL_ERROR "ANTLR download failed: ${_dl}")
  endif()
endif()

# Expose antlr4 jar to the whole project
set(ANTLR_JAR "${ANTLR_JAR}" CACHE FILEPATH "Path to the ANTLR complete jar" FORCE)