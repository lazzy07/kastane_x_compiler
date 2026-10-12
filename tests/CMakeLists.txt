
cmake_minimum_required(VERSION 3.15)

project(KasXTests LANGUAGES CXX)

set(LOGGER_PREPEND "[KasX TESTS_SUITE] ")
log_status("Building the tests: STARTED")

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
add_executable(kasx_test_suite ${UNIT_TEST_SRC_FILES})
target_link_libraries(kasx_test_suite PRIVATE GTest::GTest kasx_compiler)

# Adding test data directory
target_compile_definitions(kasx_test_suite PRIVATE KASX_TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

# Enabling auto detecting google tests (From cmake GoogleTest script)
gtest_discover_tests(kasx_test_suite)

log_status("Building the tests: FINISHED")
