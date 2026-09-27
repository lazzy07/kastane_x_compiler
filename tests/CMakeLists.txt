
cmake_minimum_required(VERSION 3.15)

project(KasXUnitTests LANGUAGES CXX)

set(LOGGER_PREPEND "[KasX UNIT_TESTS] ")
log_status("Building the unit tests: STARTED")

# ################## General project configs ###########################
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ################## Generate the tests ###########################
file(
  GLOB_RECURSE 
  UNIT_TEST_SRC_FILES 
  CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

log_status("Running google related cmake scripts: STARTED")
# Include custom fetch google cmake script
include(FetchGoogleTest)

# Include GoogleTest script from cmake
include(GoogleTest)
log_status("Running google related cmake scripts: FINISHED")

# Adding unit test executable
add_executable(kasx_unit_test ${UNIT_TEST_SRC_FILES})
target_link_libraries(kasx_unit_test PRIVATE GTest::GTest kasx_compiler)

# Enabling auto detecting google tests (From cmake GoogleTest script)
gtest_discover_tests(kasx_unit_test)

log_status("Building the unit tests: FINISHED")
