#!/usr/bin/env bash
set -euo pipefail

# ==== CONFIGURABLE STUFF =======================================
BUILD_DIR="${BUILD_DIR:-build}"
BUILD_TYPE="${BUILD_TYPE:-Debug}"

# Change this to your actual binary path
EXECUTABLE="${EXECUTABLE:-$BUILD_DIR/dist/linux/x86_64/$BUILD_TYPE/kasx}"
# ===============================================================

cmd="${1:-help}"

case "$cmd" in
configure)
  echo "[dev] Configuring CMake in '$BUILD_DIR' ($BUILD_TYPE)…"
  cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE="$BUILD_TYPE"
  ;;

reconfigure)
  echo "[dev] Removing '$BUILD_DIR' and regenerating CMake…"
  rm -rf "$BUILD_DIR"
  cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE="$BUILD_TYPE"
  ;;

build)
  echo "[dev] Building in '$BUILD_DIR'…"
  cmake --build "$BUILD_DIR" --config "$BUILD_TYPE" -j"$(nproc)"
  ;;

run)
  shift || true
  echo "[dev] Running: $EXECUTABLE $*"
  "$EXECUTABLE" "$@"
  ;;

test)
  shift || true
  echo "[dev] Building unit tests in '$BUILD_DIR'…"
  cmake --build "$BUILD_DIR" --config "$BUILD_TYPE" --target kasx_unit_test -j"$(nproc)"
  # ctest pipes the test output, so gtest turns off colors unless forced (only force it on a terminal)
  if [ -t 1 ]; then export GTEST_COLOR="${GTEST_COLOR:-yes}"; fi
  echo "[dev] Running: ctest $*"
  ctest --test-dir "$BUILD_DIR" -C "$BUILD_TYPE" --output-on-failure --no-tests=error "$@"
  ;;

docs)
  echo "[dev] Building the Docs"
  cmake --build "$BUILD_DIR" --target docs
  ;;

all)
  # configure + build + run
  echo "[dev] Configure + build + run…"
  cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE="$BUILD_TYPE"
  cmake --build "$BUILD_DIR" --config "$BUILD_TYPE" -j"$(nproc)"
  "$EXECUTABLE"
  ;;

help | *)
  cat <<EOF
Usage: $0 <command> [args]

Commands:
  configure      Run CMake configure step (no clean).
  reconfigure    Delete \$BUILD_DIR and run CMake from scratch.
  build          Build the project.
  docs           Generate the documentation.
  run [args...]  Run the built program with optional args.
  test [args...] Build and run the unit tests with ctest (args go to ctest, e.g. -R Foo -j8).
  all            Configure, build, and run (no args to program).

Env vars you can override:
  BUILD_DIR      (default: build)
  BUILD_TYPE     (default: Debug)
  EXECUTABLE     (default: \$BUILD_DIR/bin/kasx)
EOF
  ;;
esac
