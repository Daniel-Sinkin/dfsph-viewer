#!/usr/bin/env bash
set -euo pipefail
cmake -S . -B build
cmake --build build --target dfsph_viewer -j
./build/dfsph_viewer "$@"
