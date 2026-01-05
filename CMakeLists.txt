cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Cmake helper file-paths
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Set logger prepend for the main cmake configurations
set(LOGGER_PREPEND "[KasX MAIN] ")

# Include cmake helper files
include(Logger)               # For logging cmake outputs properly
include(GitVersioning)        # Versioninig the compiler properly, this is being used by the project, to keep track of the correct version
include(CodeFormat)           # Formatting the files, static checks done by the clang-tidy, clang-format
include(LazLogger)            # Adding laz_logger library for c++ logging
include(AntlrInstall)         # Adding antlr grammar compiler for grammar/parsing sabre files 
include(AntlrJar)             # Downloading antlr4 jar, to generate C++ classes

# Printing the correct project versions
log_status("Project version from Git: ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# ############ Handling correct build type ###############
# Warn if build type is not set
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    log_warn("CMAKE_BUILD_TYPE not set — defaulting to Release")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
endif()

# Configure version header
configure_file(
    "${CMAKE_SOURCE_DIR}/libs/kasx_lib/include/generated/Version.hpp.in"
    "${CMAKE_BINARY_DIR}/generated/kasx/Version.hpp"
    @ONLY
)

# ############ General Project Configs ###################

log_status("General Configs: STARTED")

project(
  kasx_compiler 
  VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# cmake helper files, (This needs to be run after the project is being set)
include(Doxygen)              # Generating documentation uisng doxygen 

log_status("General configs: FINISHED")

# ########### Output folder configs #####################

log_status("Output folder configs: STARTED")

#Get the current systems OS (In lower case), (linux, windows etc.)
string(TOLOWER "${CMAKE_SYSTEM_NAME}" _os)
log_status("Operating system set: ${_os}")

# Setting system processor architecture, this is the fallback if CMAKE_GENERATOR_PLATFORM is not defined
set(_arch "${CMAKE_SYSTEM_PROCESSOR}")

# if CMAKE_GENERATOR_PLATFORM is available, use that. (Since some compilers can crosss compile to other architectures)
if(CMAKE_GENERATOR_PLATFORM)
  set(_arch "${CMAKE_GENERATOR_PLATFORM}")
  log_status("Generator platform detected: ${_arch}")
else()
  log_status("CMAKE_GENERATOR_PLATFORM is not detected, fallback will be used for _arch: ${_arch}")
endif()

# Setting base folder for the binaries (Build configs will be handled separately)
set(_dist_base "${CMAKE_BINARY_DIR}/dist/${_os}/${_arch}")
log_status("Distribution base folder set to: ${_dist_base}")

# Adding suppot for single/multi config generation
foreach(kind ARCHIVE LIBRARY RUNTIME BUNDLE FRAMEWORK)
  set(CMAKE_${kind}_OUTPUT_DIRECTORY "${_dist_base}/$<CONFIG>")
  log_status("Output folder for ${kind} set to: ${CMAKE_${kind}_OUTPUT_DIRECTORY}")
endforeach()

# Setting installers directory
set(CMAKE_INSTALL_PREFIX "${_dist_base}/install")
log_status("Installers directory set to: ${CMAKE_INSTALL_PREFIX}")
log_status("Output folder configs: FINISHED")

# ########## Adding subprojects to the main project
log_status("Adding sub-projects: STARTED")
# Add the executable
add_subdirectory(apps/kasx)
# Add the kasx_lib
add_subdirectory(libs/kasx_lib)
log_status("Adding sub-projects: FINISHED")
