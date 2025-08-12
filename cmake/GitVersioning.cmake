# This cmake file can be used to generate versioning information from git, get the commit date, and commit hash

execute_process(
  COMMAND git describe --tags --dirty
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_VERSION
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the commit hash
execute_process(
  COMMAND git rev-parse --short HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_COMMIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Get the commit date
execute_process(
  COMMAND git log -1 --format=%cd --date=short
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_COMMIT_DATE
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
  COMMAND git describe --tags --abbrev=0
  OUTPUT_VARIABLE GIT_TAG
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Handling missing git or detached repo
if(NOT GIT_VERSION)
    set(GIT_VERSION "unknown")
    log_warn("GIT_VERSION is unknown check if git installed or head is detached, continuing with unknown")
endif()
if(NOT GIT_COMMIT_HASH)
    set(GIT_COMMIT_HASH "unknown")
    log_warn("GIT_COMMIT_HASH is unknown check if git installed or head is detached, continuing with unknown")
endif()
if(NOT GIT_COMMIT_DATE)
    set(GIT_COMMIT_DATE "unknown")
    log_warn("GIT_COMMIT_DATE is unknown check if git installed")
endif()

# Extract version numbers from tag (e.g. v1.2.3)
string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" PROJECT_VERSION_MAJOR "${GIT_TAG}")
string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" PROJECT_VERSION_MINOR "${GIT_TAG}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" PROJECT_VERSION_PATCH "${GIT_TAG}")

