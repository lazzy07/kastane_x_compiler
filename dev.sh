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
  run [args...]  Run the built program with optional args.
  all            Configure, build, and run (no args to program).

Env vars you can override:
  BUILD_DIR      (default: build)
  BUILD_TYPE     (default: Debug)
  EXECUTABLE     (default: \$BUILD_DIR/bin/my_program)
EOF
  ;;
esac
