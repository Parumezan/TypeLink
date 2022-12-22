#!/bin/sh

if [ ! -d "build" ]; then
    mkdir build
fi
if [ "$#" -eq 1 ] && [ "$1" = "debug" ]; then
    echo "-- DEBUG MODE"
    cmake -S . -B build -DCMAKE_BUILD_TYPE=debug
else
    cmake -S . -B build -DCMAKE_BUILD_TYPE=release
fi

CORES=$(grep -c ^processor /proc/cpuinfo)

cmake --build build -j $CORES