#!/usr/bin/env bash

# This script invokes CMake with Ninja for Clang

function index_code_for_rtags_if_available {
    if command -v rc >/dev/null 2>&1; then
        rc -J
    fi
}

CMAKE_INTERMEDIATE_DIR="../../build/vector-vs-list/clang/cmake"

# Rerun CMake explicitly only when cache is not setup
# Also, make sure that commands for rtags are created
if [ ! -f "$CMAKE_INTERMEDIATE_DIR/CMakeCache.txt" ]; then
    cmake -G Ninja -S .. -B $CMAKE_INTERMEDIATE_DIR -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=1
fi


pushd $CMAKE_INTERMEDIATE_DIR
ninja
index_code_for_rtags_if_available
popd




